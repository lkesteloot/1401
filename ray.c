//    Copyright 2014 Lawrence Kesteloot
// 
//    Licensed under the Apache License, Version 2.0 (the "License");
//    you may not use this file except in compliance with the License.
//    You may obtain a copy of the License at
// 
//        http://www.apache.org/licenses/LICENSE-2.0
// 
//    Unless required by applicable law or agreed to in writing, software
//    distributed under the License is distributed on an "AS IS" BASIS,
//    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//    See the License for the specific language governing permissions and
//    limitations under the License.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Fixed-point ray tracer prototype for the IBM 1401 version.

typedef signed long word;

int main()
{
    word x0, y0, z0;    // Origin of ray.
    word xv, yv, zv;    // Direction of ray.
    word xc, yc, zc;    // Center of sphere.
    word xl, yl, zl;    // Vector to light.
    word r;             // Radius of sphere.
    word r2;            // Radius of sphere squared.
    char line[200];     // Line being printed.
    word column;        // Column being printed.

    // Position of ray.
    x0 = 0;
    y0 = 0;
    z0 = 50;
    zv = -50;

    // Position of sphere.
    xc = 0;
    yc = 0;
    zc = -200;
    r = 150;
    r2 = r*r;

    // Light vector, normalized to a length of 100 (divided by sqrt(3)).
    xl = 57;
    yl = 57;
    zl = 57;

    for (yv = 50; yv >= -50; yv -= 2) {
        memset(line, ' ', sizeof(line));

        for (xv = -50, column = 0; xv <= 50; xv++, column++) {
            // Ray relative to sphere.
            word xr = x0 - xc;
            word yr = y0 - yc;
            word zr = z0 - zc;

            // Quadratic formula.
            word a = xv*xv + yv*yv + zv*zv;
            word b = 2*(xv*xr + yv*yr + zv*zr);
            word c = xr*xr + yr*yr + zr*zr - r2;
            word disc = b*b - 4*a*c;

            if (disc >= 0) {
                // Can always pick "-" because "a" is always positive.
                word t = (-b - (word) sqrt(disc)) * 100 / (2*a);

                // Make sure the intersection point is ahead of us.
                if (t >= 0) {
                    // Intersection point.
                    word x = x0 + t*xv/100;
                    word y = y0 + t*yv/100;
                    word z = z0 + t*zv/100;

                    // Sphere normal.
                    word xn = x - xc;
                    word yn = y - yc;
                    word zn = z - zc;

                    // Dot with light vector.
                    word bright = (xn*xl + yn*yl + zn*zl)/r;
                    if (bright >= 0) {
                        // Light side of sphere.

                        // Add some noise.
                        bright += (rand() % 7) - 3;

                        // Clamp.
                        if (bright < 0) {
                            bright = 0;
                        }
                        if (bright > 99) {
                            bright = 99;
                        }

                        // Convert to ASCII art.
                        line[column] = ",-:;+=*?#@"[bright/10];
                    } else {
                        // Dark side of sphere.
                        line[column] = '.';
                    }
                }
            }
        }

        // Print the line.
        line[column] = '\0';
        printf("%s\n", line);
    }

    return 0;
}
