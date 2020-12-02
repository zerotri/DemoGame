#include <WynterStorm.h>
#include <iostream>
#include <math.h>

ws_handle_t slime_spr;
ws_handle_t wizard_spr;

// called at application start, pre-api initialization
void start()
{
    auto settings = ws_system_settings();
    settings->screen.width = 320;
    settings->screen.height = 240;
    settings->screen.hidpi = true;
    settings->screen.vsync = false;
    settings->screen.title = "WynterStorm バナナ DemoGame";

    ws_display_set_clear_color( ws_color_pink );
}

// called at application end, post-api shutdown
void end()
{
}

// called after graphics api start, as well as any time a context needs reinitialization
void load()
{
    slime_spr = ws_sprite_load( "Assets/Sprites/slime.aseprite" );
    wizard_spr = ws_sprite_load( "Assets/Sprites/wizard_colored.aseprite" );
}

// called before graphics api end, as well as any time a context needs to be released
void unload()
{

}

// called on every game tick
void tick(double delta_time)
{
    static ws_coroutine_t co1([](ws_coroutine_t::ref co){
        ws_coroutine_begin(co)
        {
            std::cout << "Waiting two seconds" << std::endl;
        }
        ws_coroutine_wait(0.5f) { std::cout << "." << std::flush; }
        ws_coroutine_wait(0.5f) { std::cout << "." << std::flush; }
        ws_coroutine_wait(0.5f) { std::cout << "." << std::flush; }
        ws_coroutine_wait(0.5f)
        {
            std::cout << "Waited two seconds" << std::endl;
        }
        ws_coroutine_end
        {

        }
    });
    co1.run();
}

// called on every frame
void render(double delta_time)
{
    static double time = 0.0;
    time += delta_time;
    double x_offset = sin(time);
    double y_offset = cos(time);
    ws_draw_sprite( slime_spr, 0, round(150.0f + x_offset * 10), round(90.0f  + y_offset * 10));
    ws_draw_sprite( slime_spr, 1, 170.0f, 130.0f );
    ws_draw_sprite( slime_spr, 2, 190.0f, 170.0f );
    ws_draw_sprite( wizard_spr, 0, round(60.0f + x_offset * 20.0f), 200.0f );
}