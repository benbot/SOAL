/** @file main.cpp
 *  @brief Where the magic happens */
#include <GL/glew.h>
#include <SDL2/SDL.h>
#include <glm.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <iostream>
#include <fstream>

#include "shader.hpp"
#include "vertexArrayObject.hpp"

int main()
{
    //Let do some error checking
    GLfloat vert[] = {
            -0.5f, -0.5f, -0.5f,
            0.5f, -0.5f, -0.5f,
            0.5f,  0.5f, -0.5f,
            0.5f,  0.5f, -0.5f,
            -0.5f,  0.5f, -0.5f,
            -0.5f, -0.5f, -0.5f,

            -0.5f, -0.5f,  0.5f,
            0.5f, -0.5f,  0.5f,
            0.5f,  0.5f,  0.5f,
            0.5f,  0.5f,  0.5f,
            -0.5f,  0.5f,  0.5f,
            -0.5f, -0.5f,  0.5f,

            -0.5f,  0.5f,  0.5f,
            -0.5f,  0.5f, -0.5f,
            -0.5f, -0.5f, -0.5f,
            -0.5f, -0.5f, -0.5f,
            -0.5f, -0.5f,  0.5f,
            -0.5f,  0.5f,  0.5f,

            0.5f,  0.5f,  0.5f,
            0.5f,  0.5f, -0.5f,
            0.5f, -0.5f, -0.5f,
            0.5f, -0.5f, -0.5f,
            0.5f, -0.5f,  0.5f,
            0.5f,  0.5f,  0.5f,

            -0.5f, -0.5f, -0.5f,
            0.5f, -0.5f, -0.5f,
            0.5f, -0.5f,  0.5f,
            0.5f, -0.5f,  0.5f,
            -0.5f, -0.5f,  0.5f,
            -0.5f, -0.5f, -0.5f,

            -0.5f,  0.5f, -0.5f,
            0.5f,  0.5f, -0.5f,
            0.5f,  0.5f,  0.5f,
            0.5f,  0.5f,  0.5f,
            -0.5f,  0.5f,  0.5f,
            -0.5f,  0.5f, -0.5f
    };

    //Getting my window set up
    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window* window = SDL_CreateWindow("Lighting", 0, 0, 800, 600, SDL_WINDOW_OPENGL);
    SDL_assert(window);

    SDL_GLContext context = NULL;
    context = SDL_GL_CreateContext(window);
    SDL_assert_paranoid(context);

    glewExperimental = true;
    glewInit();


    //loop var definitions
    bool running = true;
    SDL_Event ev;

    //global GL stuff;
    glClearColor(.1f, 0.4f, 6.f, 1.f);


    //the... loop?
    while(running)
    {

        glClear(GL_COLOR_BUFFER_BIT);

        //EVENTS!!!
        if(SDL_PollEvent(&ev))
        {
            //... quit... ing?
            if(ev.type == SDL_QUIT)
                break;

            if(ev.type == SDL_KEYUP)
            {
                switch(ev.key.keysym.sym)
                {
                case SDLK_ESCAPE:
                    running = false;
                    break;
                }
            }
        }

        SDL_GL_SwapWindow(window);
    }

    return 0;
}
