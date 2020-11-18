#include <WynterStorm.h>
#include <iostream>

ws_handle_t slime_spr;
ws_handle_t wizard_spr;

// called at application start, pre-api initialization
void start()
{
    auto settings = ws_system_settings();
    settings->screen.width = 640;
    settings->screen.height = 480;
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
    // slime_spr = ws_sprite_load( "../Assets/Sprites/slime.aseprite" );
    // wizard_spr = ws_sprite_load( "../Assets/Sprites/wizard_colored.aseprite" );
}

// called before graphics api end, as well as any time a context needs to be released
void unload()
{

}

// called on every game tick
void tick(float delta_time)
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
void render(float delta_time)
{

    // ws_draw_sprite( slime_spr, 0, 150.0f, 90.0f );
    // ws_draw_sprite( slime_spr, 0, 170.0f, 130.0f );
    // ws_draw_sprite( slime_spr, 0, 190.0f, 170.0f );
    // ws_draw_sprite( sprite2, 0, 60.0f, 200.0f );
}