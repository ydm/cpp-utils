#ifndef __UTILS_GL_HPP__
#define __UTILS_GL_HPP__

#ifdef _WIN32
#include <Windows.h>
#endif

#include <GL/gl.h>
#include <freeglut/freeglut.h>

namespace utils
{
    namespace gl
    {
        /**
         * In the name of performance, this function works like this:
         * 1. It presumes the current matrix mode is GL_MODELVIEW.
         * 2. It leaves with GL_MODELVIEW set and the identity matrix loaded.
         */
        static void drawText(const std::string& s,
                             const int windowWidth = 800, const int windowHeight = 600,
                             const int positionX = 10, const int positionY = 10,
                             const float red = 1.0f, const float green = 1.0f, const float blue = 1.0f,
                             void *const font = GLUT_BITMAP_HELVETICA_18)
        {
            // Presume we're currently on GL_MODELVIEW
            glLoadIdentity();

            // Load 2D projection
            glMatrixMode(GL_PROJECTION);
            glPushMatrix();
            glLoadIdentity();
            gluOrtho2D(0, windowWidth, 0, windowHeight);

            // Draw text
            glRasterPos2i(positionX, positionY);
            glColor3f(red, green, blue);
            glPushAttrib(GL_ALL_ATTRIB_BITS);  // ydm TODO: Push just the attributes I modify!
            glDisable(GL_LIGHTING);
            glutBitmapString(font, reinterpret_cast<const unsigned char *>(s.c_str()));
            glPopAttrib();

            // Pop matrix from projection stack and go back to GL_MODELVIEW
            glPopMatrix();
            glMatrixMode(GL_MODELVIEW);
        }

        /**
         * Unobtrusive version of drawText().
         */
        static void drawText2(const std::string& s,
                              const int windowWidth = 800, const int windowHeight = 600,
                              const int positionX = 0, const int positionY = 0,
                              const float red = 1.0f, const float green = 1.0f, const float blue = 1.0f
                              void *const font = GLUT_BITMAP_HELVETICA_18)
        {
            // Store current matrix mode.
            GLint mode;
            glGetIntegerv(GL_MATRIX_MODE, &mode);

            // Load modelview, push, call drawText and pop.
            glMatrixMode(GL_MODELVIEW);
            glPushMatrix();
            drawText(s, windowWidth, windowHeight, positionX, positionY, red, green, blue, font);
            glPopMatrix();

            // Load the mode as it was before calling this function.
            glMatrixMode(mode);
        }
    }
}

#endif // __UTILS_GL_HPP__
