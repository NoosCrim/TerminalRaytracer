#include <iostream>
#include "camera.h"
#include "vec3.h"
#include "vec4.h"
#include "mat3.h"
#include "mat4.h"
#include "light.h"
#include "object.h"
#include <vector>
int main()
{
    point_light* LS = new point_light(vec3(5, -4, 6), 1, 0.01);
    light* LSB[1] = { LS }; // light source buffer
    object* OB[] = { 
        new triangle(vertex(vec3(-1 + 1.5f,-1, 1), vec3( 0, 0, 1), 1, 0.3), vertex(vec3( 1 + 1.5f,-1, 1), vec3( 0, 0, 1), 1, 0.3), vertex(vec3( 1 + 1.5f, 1, 1), vec3( 0, 0, 1), 1, 0.3)),
        new triangle(vertex(vec3(-1 + 1.5f,-1, 1), vec3( 0, 0, 1), 1, 0.3), vertex(vec3( 1 + 1.5f, 1, 1), vec3( 0, 0, 1), 1, 0.3), vertex(vec3(-1 + 1.5f, 1, 1), vec3( 0, 0, 1), 1, 0.3)),
        new triangle(vertex(vec3(-1 + 1.5f,-1,-1), vec3( 0, 0,-1), 1, 0.3), vertex(vec3( 1 + 1.5f, 1,-1), vec3( 0, 0,-1), 1, 0.3), vertex(vec3( 1 + 1.5f,-1,-1), vec3( 0, 0,-1), 1, 0.3)),
        new triangle(vertex(vec3(-1 + 1.5f,-1,-1), vec3( 0, 0,-1), 1, 0.3), vertex(vec3(-1 + 1.5f, 1,-1), vec3( 0, 0,-1), 1, 0.3), vertex(vec3( 1 + 1.5f, 1,-1), vec3( 0, 0,-1), 1, 0.3)),
        new triangle(vertex(vec3(-1 + 1.5f, 1,-1), vec3( 0, 1, 0), 1, 0.3), vertex(vec3(-1 + 1.5f, 1, 1), vec3( 0, 1, 0), 1, 0.3), vertex(vec3( 1 + 1.5f, 1, 1), vec3( 0, 1, 0), 1, 0.3)),
        new triangle(vertex(vec3(-1 + 1.5f, 1,-1), vec3( 0, 1, 0), 1, 0.3), vertex(vec3( 1 + 1.5f, 1, 1), vec3( 0, 1, 0), 1, 0.3), vertex(vec3( 1 + 1.5f, 1,-1), vec3( 0, 1, 0), 1, 0.3)),
        new triangle(vertex(vec3(-1 + 1.5f,-1,-1), vec3( 0,-1, 0), 1, 0.3), vertex(vec3( 1 + 1.5f,-1, 1), vec3( 0,-1, 0), 1, 0.3), vertex(vec3(-1 + 1.5f,-1, 1), vec3( 0,-1, 0), 1, 0.3)),
        new triangle(vertex(vec3(-1 + 1.5f,-1,-1), vec3( 0,-1, 0), 1, 0.3), vertex(vec3( 1 + 1.5f,-1,-1), vec3( 0,-1, 0), 1, 0.3), vertex(vec3( 1 + 1.5f,-1, 1), vec3( 0,-1, 0), 1, 0.3)),
        new triangle(vertex(vec3( 1 + 1.5f,-1,-1), vec3( 1, 0, 0), 1, 0.3), vertex(vec3( 1 + 1.5f, 1,-1), vec3( 1, 0, 0), 1, 0.3), vertex(vec3( 1 + 1.5f, 1, 1), vec3( 1, 0, 0), 1, 0.3)),
        new triangle(vertex(vec3( 1 + 1.5f,-1,-1), vec3( 1, 0, 0), 1, 0.3), vertex(vec3( 1 + 1.5f, 1, 1), vec3( 1, 0, 0), 1, 0.3), vertex(vec3( 1 + 1.5f,-1, 1), vec3( 1, 0, 0), 1, 0.3)),
        new triangle(vertex(vec3(-1 + 1.5f,-1,-1), vec3(-1, 0, 0), 1, 0.3), vertex(vec3(-1 + 1.5f, 1, 1), vec3(-1, 0, 0), 1, 0.3), vertex(vec3(-1 + 1.5f, 1,-1), vec3(-1, 0, 0), 1, 0.3)),
        new triangle(vertex(vec3(-1 + 1.5f,-1,-1), vec3(-1, 0, 0), 1, 0.3), vertex(vec3(-1 + 1.5f,-1, 1), vec3(-1, 0, 0), 1, 0.3), vertex(vec3(-1 + 1.5f, 1, 1), vec3(-1, 0, 0), 1, 0.3)),
        new triangle(vertex(vec3(-1 - 1.5f,-1, 1), vec3( 0, 0, 1), 1, 0.3), vertex(vec3( 1 - 1.5f,-1, 1), vec3( 0, 0, 1), 1, 0.3), vertex(vec3( 1 - 1.5f, 1, 1), vec3( 0, 0, 1), 1, 0.3)),
        new triangle(vertex(vec3(-1 - 1.5f,-1, 1), vec3( 0, 0, 1), 1, 0.3), vertex(vec3( 1 - 1.5f, 1, 1), vec3( 0, 0, 1), 1, 0.3), vertex(vec3(-1 - 1.5f, 1, 1), vec3( 0, 0, 1), 1, 0.3)),
        new triangle(vertex(vec3(-1 - 1.5f,-1,-1), vec3( 0, 0,-1), 1, 0.3), vertex(vec3( 1 - 1.5f, 1,-1), vec3( 0, 0,-1), 1, 0.3), vertex(vec3( 1 - 1.5f,-1,-1), vec3( 0, 0,-1), 1, 0.3)),
        new triangle(vertex(vec3(-1 - 1.5f,-1,-1), vec3( 0, 0,-1), 1, 0.3), vertex(vec3(-1 - 1.5f, 1,-1), vec3( 0, 0,-1), 1, 0.3), vertex(vec3( 1 - 1.5f, 1,-1), vec3( 0, 0,-1), 1, 0.3)),
        new triangle(vertex(vec3(-1 - 1.5f, 1,-1), vec3( 0, 1, 0), 1, 0.3), vertex(vec3(-1 - 1.5f, 1, 1), vec3( 0, 1, 0), 1, 0.3), vertex(vec3( 1 - 1.5f, 1, 1), vec3( 0, 1, 0), 1, 0.3)),
        new triangle(vertex(vec3(-1 - 1.5f, 1,-1), vec3( 0, 1, 0), 1, 0.3), vertex(vec3( 1 - 1.5f, 1, 1), vec3( 0, 1, 0), 1, 0.3), vertex(vec3( 1 - 1.5f, 1,-1), vec3( 0, 1, 0), 1, 0.3)),
        new triangle(vertex(vec3(-1 - 1.5f,-1,-1), vec3( 0,-1, 0), 1, 0.3), vertex(vec3( 1 - 1.5f,-1, 1), vec3( 0,-1, 0), 1, 0.3), vertex(vec3(-1 - 1.5f,-1, 1), vec3( 0,-1, 0), 1, 0.3)),
        new triangle(vertex(vec3(-1 - 1.5f,-1,-1), vec3( 0,-1, 0), 1, 0.3), vertex(vec3( 1 - 1.5f,-1,-1), vec3( 0,-1, 0), 1, 0.3), vertex(vec3( 1 - 1.5f,-1, 1), vec3( 0,-1, 0), 1, 0.3)),
        new triangle(vertex(vec3( 1 - 1.5f,-1,-1), vec3( 1, 0, 0), 1, 0.3), vertex(vec3( 1 - 1.5f, 1,-1), vec3( 1, 0, 0), 1, 0.3), vertex(vec3( 1 - 1.5f, 1, 1), vec3( 1, 0, 0), 1, 0.3)),
        new triangle(vertex(vec3( 1 - 1.5f,-1,-1), vec3( 1, 0, 0), 1, 0.3), vertex(vec3( 1 - 1.5f, 1, 1), vec3( 1, 0, 0), 1, 0.3), vertex(vec3( 1 - 1.5f,-1, 1), vec3( 1, 0, 0), 1, 0.3)),
        new triangle(vertex(vec3(-1 - 1.5f,-1,-1), vec3(-1, 0, 0), 1, 0.3), vertex(vec3(-1 - 1.5f, 1, 1), vec3(-1, 0, 0), 1, 0.3), vertex(vec3(-1 - 1.5f, 1,-1), vec3(-1, 0, 0), 1, 0.3)),
        new triangle(vertex(vec3(-1 - 1.5f,-1,-1), vec3(-1, 0, 0), 1, 0.3), vertex(vec3(-1 - 1.5f,-1, 1), vec3(-1, 0, 0), 1, 0.3), vertex(vec3(-1 - 1.5f, 1, 1), vec3(-1, 0, 0), 1, 0.3))

        };// renderable object buffer
    perspectiveCameraFlat mainCamera(vec3(0, -1.f, 10), vec3(0, 1, 0), vec3(1, 0, 0), 180, 150, 1.2, 1);
    mainCamera.pos = mat3::RotY(-0.5f) * mat3::RotX(0.2f) * mainCamera.pos;
    mainCamera.fwd = mat3::RotY(-0.5f) * mat3::RotX(0.2f) * mainCamera.fwd;
    mainCamera.right = mat3::RotY(-0.5f) * mat3::RotX(0.2f) * mainCamera.right;
    mat3 m = mat3::RotY(0.5f);
    for (int i = 0; i < 10; i++)
    {
        mainCamera.pos = m * mainCamera.pos;
        mainCamera.fwd = m * mainCamera.fwd;
        mainCamera.right = m * mainCamera.right;
        mainCamera.up = m * mainCamera.up;
        mainCamera.Render(OB, 24, LSB, 1, 0.f, 0.05f, 0.99f, 0.5f, 1);
        mainCamera.Display();
    }
    
    for (light* LS : LSB)
        delete LS;
    for (object* O : OB)
        delete O;
}
