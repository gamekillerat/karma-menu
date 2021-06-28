#include "stdafx.h"
bool ingame_keyboard::on_ = false;
bool ingame_keyboard::finished_process_ = false;

ingame_keyboard::ingame_keyboard(const std::string& default_text, std::string* outputs)
{
	if (on_)
	{
		finished_process_ = false;
		gameplay::display_onscreen_keyboard(true, nullptr, nullptr, const_cast<char*>(default_text.c_str()), nullptr, nullptr,
		                                    nullptr, 200);
		while (gameplay::update_onscreen_keyboard() == 0) WAIT(0);
		*outputs = output();
		finished_process_ = true;
		stop();
	}
}

void ingame_keyboard::start()
{
	on_ = true;
}

void ingame_keyboard::stop()
{
	on_ = false;
}

std::string ingame_keyboard::output() const
{
	return gameplay::get_onscreen_keyboard_result();
}
