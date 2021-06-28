#include "stdafx.h"


void loop_shite()
{

}
bool starting = true;
bool tbool = false;
int tint = 0;
float tfloat = 0.f;
int tvectorint = 0;
std::string keyboardoutput;
std::vector<std::string> tvector{ "lol", "skid" };
void draw_shite()
{
    auto menu = new KARMA::menu;

    loop_shite();

    if (starting)
    {
        std::ifstream infile(".//KARMA//config.json");
        if (!infile.good())
            menu->write_default_keys();
        std::ifstream infile2(".//KARMA//theme.json");
        if (!infile2.good())
            menu->write_theme_defaults();
        menu->read_keys();
        menu->read_theme();
        starting = false;
    }
    else
    {
        menu->clear_vars();
        menu->keys();
        if (menu->is_open())
        {
            menu->clear_options();
            menu->set_main_title("~r~KARMA.");
            menu->insert_sub("Main", "~r~KARMA.", [menu]
            {
                menu->push_option(new option("option"));
                menu->push_option(new option("int option", &tint));
                menu->push_option(new option("float option", &tfloat));
                menu->push_option(new option("vector option", tvector, &tvectorint));
                menu->push_option(new option("keyboard option", new ingame_keyboard("bottom text", &keyboardoutput)));
            });
            menu->insert_sub("settings", "Settings", [menu]
            {
                menu->push_option({ "Title / Footer", "title" });
                menu->push_option({ "Option Rect", "optionrect" });
                menu->push_option({ "Scroller", "scroller" });
                menu->push_option({ "Non-Selected Text", "ntext" });
                menu->push_option({ "Selected Text", "text" });
                if (menu->push_option({ "Load" }))
                    menu->read_theme();
                if (menu->push_option({ "Save" }))
                    menu->save_theme();
                if (menu->push_option({ "Reset To Default" }))
                {
                    menu->write_theme_defaults();
                    menu->read_theme();
                }
            });
            menu->insert_sub("title", "Settings (Title / Footer)", [menu]
            {
                menu->push_option(new option("Red", &TitleR, 0, 255));
                menu->push_option(new option("Green", &TitleG, 0, 255));
                menu->push_option(new option("Blue", &TitleB, 0, 255));
                menu->push_option(new option("Alpha", &TitleA, 0, 255));
            });
            menu->insert_sub("optionrect", "Settings (Option Rect)", [menu]
            {
                menu->push_option(new option("Red", &OptionsR, 0, 255));
                menu->push_option(new option("Green", &OptionsG, 0, 255));
                menu->push_option(new option("Blue", &OptionsB, 0, 255));
                menu->push_option(new option("Alpha", &OptionsA, 0, 255));
            });
            menu->insert_sub("scroller", "Settings (Scroller)", [menu]
            {
                menu->push_option(new option("Red", &ScrollerR, 0, 255));
                menu->push_option(new option("Green", &ScrollerG, 0, 255));
                menu->push_option(new option("Blue", &ScrollerB, 0, 255));
                menu->push_option(new option("Alpha", &ScrollerA, 0, 255));
                menu->push_option(new option("Speed", &ScrollerSpeed, 0.00005f, 1.0f, 0.0001f));
            });
            menu->insert_sub("ntext", "Settings (Non-Selected Text)", [menu]
            {
                menu->push_option(new option("Red", &NotSelectedOptionTextR, 0, 255));
                menu->push_option(new option("Green", &NotSelectedOptionTextG, 0, 255));
                menu->push_option(new option("Blue", &NotSelectedOptionTextB, 0, 255));
                menu->push_option(new option("Alpha", &NotSelectedOptionTextA, 0, 255));
            });
            menu->insert_sub("text", "Settings (Selected Text)", [menu]
            {
                menu->push_option(new option("Red", &SelectedOptionTextR, 0, 255));
                menu->push_option(new option("Green", &SelectedOptionTextG, 0, 255));
                menu->push_option(new option("Blue", &SelectedOptionTextB, 0, 255));
                menu->push_option(new option("Alpha", &SelectedOptionTextA, 0, 255));
            });
            menu->render_options();
            delete menu;
        }
    }
}

void main()
{
	while (true)
	{
		draw_shite();
		WAIT(0);
	}
}

void ScriptMain()
{
    srand(GetTickCount());
    main();
}
