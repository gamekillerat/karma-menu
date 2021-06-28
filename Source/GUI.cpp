#include "stdafx.h"
#define NULL_FLOAT 0.0f
int guac::menu::current_menu_ = Main;
float guac::menu::width_ = 0.255f;
float guac::menu::menux_ = 0.615f;
bool guac::menu::visible_ = false;
int guac::menu::current_option_ = 0;
int guac::menu::previous_option_ = 0;
bool guac::menu::option_pressed_ = false;
bool guac::menu::left_pressed_ = false;
bool guac::menu::right_pressed_ = false;
float guac::menu::right_margin_ = menux_ + 0.24f;
int previousmenu;
std::vector<guac::option_args> guac::menu::option_args_;
std::vector<int> guac::menu::previous_menus_;
//std::vector<std::string> Guac::menu::whoatech = ;
bool ten_keyless = false;
std::string guac::menu::subtitlen = "u gay ngga";
menu_keys keys = {
	VK_MULTIPLY,
	VK_NUMPAD2,
	VK_NUMPAD8,
	VK_NUMPAD0,
	VK_NUMPAD6,
	VK_NUMPAD4,
	VK_NUMPAD5,
	VK_F5
};
menu_keys arrow_keys = {
	VK_F4,
	VK_DOWN,
	VK_UP,
	VK_BACK,
	VK_LEFT,
	VK_RIGHT,
	VK_RETURN,
	VK_F5
};
menu_keys keys_backup = {
	VK_MULTIPLY,
	VK_NUMPAD2,
	VK_NUMPAD8,
	VK_NUMPAD0,
	VK_NUMPAD6,
	VK_NUMPAD4,
	VK_NUMPAD5,
	VK_F5
};
guac::menu::menu()
= default;

std::vector<std::string> nullvector{ "" };
std::vector<int> intnullv;
guac::option_args::option_args(const std::string& option_text)
{
	option_text_ = option_text;
	bool_ = nullptr;
	int_ = nullptr;
	float_ = nullptr;
	mini_ = NULL;
	maxi_ = NULL;
	minf_ = NULL;
	maxf_ = NULL;
	stepi_ = NULL;
	stepf_ = NULL;
	submenu_ = NULL;
	string_vector_ = { "" };
}

guac::option_args::option_args(const std::string& option_text, const int submenu)
{
	option_text_ = option_text;
	bool_ = nullptr;
	int_ = nullptr;
	float_ = nullptr;
	mini_ = NULL;
	maxi_ = NULL;
	minf_ = NULL;
	maxf_ = NULL;
	stepi_ = NULL;
	stepf_ = NULL;
	submenu_ = submenu;
	string_vector_ = { "" };
}

guac::option_args::option_args(const std::string& option_text, bool* boool)
{
	option_text_ = option_text;
	bool_ = boool;
	int_ = nullptr;
	float_ = nullptr;
	mini_ = NULL;
	maxi_ = NULL;
	minf_ = NULL;
	maxf_ = NULL;
	stepi_ = NULL;
	stepf_ = NULL;
	submenu_ = NULL;
	string_vector_ = { "" };
}

guac::option_args::option_args(const std::string& option_text, int* innnt, const int min, const int max, const int step)
{
	option_text_ = option_text;
	bool_ = nullptr;
	int_ = innnt;
	float_ = nullptr;
	mini_ = min;
	maxi_ = max;
	minf_ = NULL;
	maxf_ = NULL;
	stepi_ = step;
	stepf_ = NULL;
	submenu_ = NULL;
	string_vector_ = { "" };
}

guac::option_args::option_args(const std::string& option_text, float* floaat, const float min, const float max, const float step)
{
	option_text_ = option_text;
	bool_ = nullptr;
	int_ = nullptr;
	float_ = floaat;
	mini_ = NULL;
	maxi_ = NULL;
	minf_ = min;
	maxf_ = max;
	stepi_ = NULL;
	stepf_ = step;
	submenu_ = NULL;
	string_vector_ = { "" };
}

guac::option_args::option_args(const std::string& option_text, const std::vector<std::string>& string_vector,
	int* current_position)
{
	option_text_ = option_text;
	bool_ = nullptr;
	int_ = current_position;
	float_ = nullptr;
	mini_ = NULL;
	maxi_ = NULL;
	minf_ = NULL;
	maxf_ = NULL;
	stepi_ = NULL;
	stepf_ = NULL;
	submenu_ = NULL;
	string_vector_ = string_vector;
}
int current_frame = 1;

bool guac::menu::is_open()
{
	return visible_;
}
int titleticker = GetCurrentTime();
int gifdelay = 36;

void resettitleticker()
{
	titleticker = GetCurrentTime();
}

bool dd = false;
std::string zxd;
char* string2;
void guac::menu::add_title(const std::string& title_str, const bool globe)
{
	//rect(menux_, 0.1f, width, 0.1f, 153, 153, 102, 255);
	in_game_img(static_cast<char*>("sinister"), "anime", menux_, 0.1f, width_, 0.1f, 255, 255, 255, 200);

	/*
	if (static_cast<int>(GetCurrentTime()) - titleticker >= gifdelay) {
		if (current_frame == 27)
			current_frame = 1;
		if (current_frame <= 9)
		{
			zxd = "sprite-0" + to_string(current_frame);
		}
		else
		{
			zxd = "sprite-" + to_string(current_frame);
		}
		string2 = const_cast<char*>(zxd.c_str());
		current_frame++;
		resettitleticker();
	}

	in_game_img(static_cast<char*>("gif"), string2, menux_, 0.1f, width_, 0.1f, 255, 255, 255, 200);*/
	str(title_str, 1, menux_, 0.075f, 1.027f, 1.027f, 255, 255, 255, 255, false, true, true);
	if (globe)
		render_globe(menux_ + 0.384f, 0.539741f, width_ + 0.8868f, 1.08714f, 255, 255, 255);
}

void guac::menu::add_subtitle(const std::string& title_str)
{
	//rect(menux_, 0.1f, width, 0.1f, 153, 153, 102, 255);
	//str(title_str, 7, menux_ - 0.1f, 0.125f, 1.f, 0.5f, 255, 255, 255, 255, true, true, false);
	subtitlen = title_str;
}

void guac::menu::clear_vars()
{
	left_pressed_ = false;
	right_pressed_ = false;
	option_pressed_ = false;
	left_pressed_ = false;
	right_pressed_ = false;
}

void guac::menu::clear_options()
{
	option_args_.clear();
}

int ticker = GetCurrentTime();
int delay = 125;

void resettick()
{
	ticker = GetCurrentTime();
}
float prevf;
void guac::menu::reset_scroller() {
	current_option_ = 0;
	previous_option_ = 0;
	prevf = 0 * 0.038f + 0.168f;
}
void guac::menu::check_keys()
{
	if (static_cast<int>(GetCurrentTime()) - ticker >= delay)
	{
		if (ten_keyless)
			keys = arrow_keys;
		else
			keys = keys_backup;
		if (GetAsyncKeyState(keys.left))
		{
			left_pressed_ = true;
		}
		if (GetAsyncKeyState(keys.right))
		{
			right_pressed_ = true;
		}
		if (GetAsyncKeyState(keys.select))
		{
			option_pressed_ = true;
		}
		if (GetAsyncKeyState(keys.open))
		{
			visible_ = !visible_;
			current_menu_ = Main;
			current_option_ = 0;
		}
		if (GetAsyncKeyState(keys.down))
		{
			if (current_option_ <= static_cast<int>(option_args_.size()) - 2)
			{
				current_option_++;
			}
			else
			{
				current_option_ = 0;
			}
		}
		if (GetAsyncKeyState(keys.up))
		{
			if (current_option_ >= 1)
				current_option_--;
			else
				current_option_ = option_args_.size() - 1;
		}
		if (GetAsyncKeyState(keys.back))
		{
			if (previous_menus_ == intnullv)
				visible_ = false;
			else
			{
				current_menu_ = previous_menus_.back();
				previous_menus_.pop_back();
				reset_scroller();
			}
		}
		if (GetAsyncKeyState(keys.numpad_arrows_switch))
			ten_keyless = !ten_keyless;
		resettick();
	}
}

void guac::rect(const float x, const float y, const float sx, const float sy, const int r, const int g, const int b,
	const int a)
{
	graphics::draw_rect(x, y, sx, sy, r, g, b, a);
}
bool guac::menu::is_current_option_pressed()
{
	return static_cast<int>(option_args_.size()) == current_option_ && option_pressed_;
}
bool guac::menu::is_current_option_pressed2()
{
	return static_cast<int>(option_args_.size()) - 1 == current_option_ && option_pressed_;
}
bool guac::menu::is_current_option_selected()
{
	return static_cast<int>(option_args_.size()) == current_option_;
}
bool guac::menu::push_option(const option_args& args)
{

	if (args.get_int() != nullptr && args.get_vector() == nullvector) {
		if (is_current_option_selected()) {
			if (left_pressed_) {
				args.set_int(*args.get_int() + args.get_stepi());
				if (*args.get_int() >= args.get_maxi())
					args.set_int(args.get_mini());
			}
			if (right_pressed_) {
				args.set_int(*args.get_int() - args.get_stepi());
				if (*args.get_int() <= args.get_mini())
					args.set_int(args.get_maxi());
			}
		}
	}
	else if (args.get_bool() != nullptr) {
		if (is_current_option_pressed())
		{
			args.set_bool_opposite();
		}
	}
	else if (args.get_float() != nullptr) {
		if (is_current_option_selected())
		{
			if (left_pressed_) {
				args.set_float(*args.get_float() + args.get_stepf());
				if (*args.get_float() >= args.get_maxf())
					args.set_float(args.get_minif());
			}
			if (right_pressed_) {
				args.set_float(*args.get_float() - args.get_stepf());
				if (*args.get_float() <= args.get_minif())
					args.set_float(args.get_maxf());
			}
		}
	}
	else if (args.get_submenu() != NULL) {
		if (is_current_option_pressed())
		{
			previous_menus_.push_back(current_menu_);
			current_menu_ = args.get_submenu();
			reset_scroller();
		}
	}
	else if (args.get_vector() != nullvector && args.get_int() != nullptr)
	{
		if (is_current_option_selected()) {
			if (left_pressed_) {
				args.set_int(*args.get_int() + 1);
				if (*args.get_int() >= static_cast<int>(args.get_vector().size()))
					args.set_int(0);
			}
			if (right_pressed_) {
				args.set_int(*args.get_int() - 1);
				if (*args.get_int() < 0)
					args.set_int(static_cast<int>(args.get_vector().size()) - 1);
			}
		}
	}
	option_args_.push_back(args);
	return is_current_option_pressed2();
}
bool guac::menu::push_option(const option_args* args)
{

	if (args->get_int() != nullptr && args->get_vector() == nullvector) {
		if (is_current_option_selected()) {
			if (left_pressed_) {
				args->set_int(*args->get_int() + args->get_stepi());
				if (*args->get_int() >= args->get_maxi())
					args->set_int(args->get_mini());
			}
			if (right_pressed_) {
				args->set_int(*args->get_int() - args->get_stepi());
				if (*args->get_int() <= args->get_mini())
					args->set_int(args->get_maxi());
			}
		}
	}
	else if (args->get_bool() != nullptr) {
		if (is_current_option_pressed())
		{
			args->set_bool_opposite();
		}
	}
	else if (args->get_float() != nullptr) {
		if (is_current_option_selected())
		{
			if (left_pressed_) {
				args->set_float(*args->get_float() + args->get_stepf());
				if (*args->get_float() >= args->get_maxf())
					args->set_float(args->get_minif());
			}
			if (right_pressed_) {
				args->set_float(*args->get_float() - args->get_stepf());
				if (*args->get_float() <= args->get_minif())
					args->set_float(args->get_maxf());
			}
		}
	}
	else if (args->get_submenu() != NULL) {
		if (is_current_option_pressed())
		{
			previous_menus_.push_back(current_menu_);
			current_menu_ = args->get_submenu();
			reset_scroller();
		}
	}
	else if (args->get_vector() != nullvector && args->get_int() != nullptr)
	{
		if (is_current_option_selected()) {
			if (left_pressed_) {
				args->set_int(*args->get_int() + 1);
				if (*args->get_int() >= static_cast<int>(args->get_vector().size()))
					args->set_int(0);
			}
			if (right_pressed_) {
				args->set_int(*args->get_int() - 1);
				if (*args->get_int() < 0)
					args->set_int(static_cast<int>(args->get_vector().size()) - 1);
			}
		}
	}
	option_args_.push_back(*args);
	delete args;
	return is_current_option_pressed2();
}

void guac::str(const std::string& str, const int font, const float x, const float y, const float sx, const float sy,
	const int r, const int g, const int b, const int a, const bool outline, const bool shadow,
	const bool center)
{
	ui::set_text_font(font);
	ui::set_text_scale(sx, sy);
	ui::set_text_colour(r, g, b, a);
	if (outline)
		ui::set_text_outline();
	if (shadow)
		ui::set_text_drop_shadow();
	if (center)
		ui::set_text_centre(1);
	ui::begin_text_command_display_text(static_cast<char*>("STRING"));
	const auto drawing_text = str.c_str();
	ui::add_text_component_substring_player_name(const_cast<char*>(drawing_text));
	ui::end_text_command_display_text(x, y);
}

void guac::in_game_img(char* dict, char* texture, const float x, const float y, const float sx, const float sy,
	const int r, const int g, const int b, const int a, const float heading)
{
	if (!graphics::has_streamed_texture_dict_loaded(dict))
	{
		graphics::request_streamed_texture_dict(dict, false);
	}
	else
	{
		graphics::draw_sprite(dict, texture, x, y, sx, sy, heading, r, g, b, a);
	}
}

float guac::menu::get_text_width(const std::string& text, const int font, const float size)
{
	ui::_begin_text_command_width(static_cast<char*>("STRING"));
	ui::set_text_font(font);
	ui::set_text_scale(size, size);
	ui::add_text_component_substring_player_name(const_cast<char*>(text.c_str()));
	return ui::_end_text_command_get_width(true);
}

float guac::menu::right_align_text_coord(const std::string& text)
{
	return menux_ + width_ / 2.f - get_text_width(text, 0, 0.35f);
}
void guac::menu::render_options()
{
	auto start_point = 0;
	auto end_point = option_args_.size() > 16 ? 16 : option_args_.size();

	if (option_args_.size() > 16 && current_option_ >= 16)
	{
		start_point = current_option_ - 16 + 1; // current_option_ - 15
		end_point = current_option_ + 1;
	}

	for (auto i = start_point, j = 0; i < static_cast<int>(end_point); ++i, ++j)
	{
		if (current_option_ == i)
		{
			graphics::_set_2d_layer(7);
			//str("test", 0, right_align_text_coord("test"), j * 0.038f + 0.155f, 0.35f, 0.35f, 255, 0, 0, 255, false, false, false);
			nasty_scroll(&previous_option_, j);
			if (option_args_[i].get_int() != nullptr && option_args_[i].get_vector() == nullvector)
			{
				stringstream ss;
				ss << *option_args_[i].get_int();
				stringstream ss2;
				ss2 << option_args_[i].get_maxi();
				const auto fltstr = "< " + ss.str() + " > / " + ss2.str();
				str(fltstr, 0, right_align_text_coord(fltstr), j * 0.038f + 0.155f, 0.35f, 0.35f, 0, 0, 0, 255, false, false, false);
			}
			if (option_args_[i].get_float() != nullptr)
			{
				stringstream ss;
				ss << *option_args_[i].get_float();
				stringstream ss2;
				ss2 << option_args_[i].get_maxf();
				const auto fltstr = "< " + ss.str() + " > / " + ss2.str();
				str(fltstr, 0, right_align_text_coord(fltstr), j * 0.038f + 0.155f, 0.35f, 0.35f, 0, 0, 0, 255, false, false, false);
			}
			if (option_args_[i].get_submenu() != NULL)
			{
				const auto submenustr = ">>";
				str(submenustr, 0, right_align_text_coord(submenustr), j * 0.038f + 0.155f, 0.35f, 0.35f, 0, 0, 0, 255, false, false, false);
			}
			if (option_args_[i].get_bool() != nullptr)
			{
				in_game_img(static_cast<char*>("shared"),
					*option_args_[i].get_bool() ? static_cast<char*>("medaldot_32") : static_cast<char*>("emptydot_32"), menux_ + 0.12f,
					j * 0.038f + 0.168f, 0.02f, 0.04f, 0, 0, 0, 255);
			}
			if (option_args_[i].get_vector() != nullvector && option_args_[i].get_int() != nullptr)
			{
				const auto countint = *option_args_[i].get_int() + 1;
				stringstream ss;
				ss << countint;
				stringstream ss2;
				ss2 << static_cast<int>(option_args_[i].get_vector().size());
				const auto fltstr = "[" + option_args_[i].get_vector()[*option_args_[i].get_int()] + "]" + "~c~ (" + ss.str() + " / " + ss2.str() + ")";
				str(fltstr, 0, right_align_text_coord(fltstr), j * 0.038f + 0.155f, 0.35f, 0.35f, 0, 0, 0, 255, false, false, false);
			}
			str(option_args_[i].get_text(), 0, menux_ - 0.123f, j * 0.038f + 0.155f, 0.35f, 0.35f, 0, 0, 0, 255, false, false,
				false);
			graphics::_set_2d_layer(1);






			//rect(menux_, j * 0.038f + 0.168f, width_, 0.038f, 255, 255, 255, 180);
		}
		else
		{
			if (option_args_[i].get_int() != nullptr && option_args_[i].get_vector() == nullvector)
			{
				stringstream ss;
				ss << *option_args_[i].get_int();
				stringstream ss2;
				ss2 << option_args_[i].get_maxi();
				const auto fltstr = "< " + ss.str() + " > / " + ss2.str();
				str(fltstr, 0, right_align_text_coord(fltstr), j * 0.038f + 0.155f, 0.35f, 0.35f, 255, 255, 255, 255, false, false, false);
			}

			if (option_args_[i].get_float() != nullptr)
			{
				stringstream ss;
				ss << *option_args_[i].get_float();
				stringstream ss2;
				ss2 << option_args_[i].get_maxf();
				const auto fltstr = "< " + ss.str() + " > / " + ss2.str();
				str(fltstr, 0, right_align_text_coord(fltstr), j * 0.038f + 0.155f, 0.35f, 0.35f, 255, 255, 255, 255, false, false, false);
			}
			if (option_args_[i].get_submenu() != NULL)
			{
				const auto submenustr = ">>";
				str(submenustr, 0, right_align_text_coord(submenustr), j * 0.038f + 0.155f, 0.35f, 0.35f, 255, 255, 255, 255, false, false, false);
			}
			if (option_args_[i].get_vector() != nullvector && option_args_[i].get_int() != nullptr)
			{
				const auto countint = *option_args_[i].get_int() + 1;
				stringstream ss;
				ss << countint;
				stringstream ss2;
				ss2 << static_cast<int>(option_args_[i].get_vector().size());
				const auto fltstr = "[" + option_args_[i].get_vector()[*option_args_[i].get_int()] + "]" + "~c~ (" + ss.str() + " / " + ss2.str() + ")";
				str(fltstr, 0, right_align_text_coord(fltstr), j * 0.038f + 0.155f, 0.35f, 0.35f, 255, 255, 255, 255, false, false, false);
			}
			if (option_args_[i].get_bool() != nullptr)
			{
				graphics::_set_2d_layer(8);
				in_game_img(static_cast<char*>("shared"),
					*option_args_[i].get_bool() ? static_cast<char*>("medaldot_32") : static_cast<char*>("emptydot_32"), menux_ + 0.12f,
					j * 0.038f + 0.168f, 0.02f, 0.04f, 255, 255, 255, 255);
			}
			graphics::_set_2d_layer(1);
			rect(menux_, j * 0.038f + 0.168f, width_, 0.038f, 0, 0, 0, 180);
			str(option_args_[i].get_text(), 0, menux_ - 0.123f, j * 0.038f + 0.155f, 0.35f, 0.35f, 255, 255, 255, 255, false, false,
				false);
		}
	}

	in_game_img(static_cast<char*>("sinister"), "anime", menux_,
		(option_args_.size() > 16 ? 16 : option_args_.size()) * 0.038f + 0.168f, width_, 0.038f, 255, 255, 255,
		200);
	str(subtitlen, 1, menux_ - 0.123f, (option_args_.size() > 16 ? 16 : option_args_.size()) * 0.038f + 0.155f, 0.35f, 0.35f, 255, 255, 255, 255, false, false,
		false);
}


float guac::menu::conv360(float base, const float min, const float max)
{
	if (min == max) return min;
	const auto f_var0 = max - min;
	base -= round(base - min / f_var0) * f_var0;
	if (base < min) base += f_var0;
	return base;
}

void guac::menu::render_globe(const float x, const float y, const float sx, const float sy, const int r, const int g,
	const int b)
{
	float g_glare_dir = 0;
	const auto g_glare_handle = GRAPHICS::REQUEST_SCALEFORM_MOVIE(static_cast<char*>("MP_MENU_GLARE"));
	const auto rot = CAM::_GET_GAMEPLAY_CAM_ROT(2);
	const auto dir = conv360(rot.z, 0, 360);
	if ((g_glare_dir == 0 || g_glare_dir - dir > 0.5) || g_glare_dir - dir < -0.5)
	{
		g_glare_dir = dir;
		graphics::call_scaleform_movie_method(g_glare_handle, static_cast<char*>("SET_DATA_SLOT"));
		graphics::_add_scaleform_movie_method_parameter_float(g_glare_dir);
		graphics::end_scaleform_movie_method();
	}
	graphics::draw_scaleform_movie(g_glare_handle, x, y, sx, sy, r, g, b, 20, 0);
	graphics::_screen_draw_position_end();
}



void guac::menu::nasty_scroll(int* prev, const int cur)
{
	if (prevf == NULL)
		prevf = *prev * 0.038f + 0.168f;
	const auto curf = cur * 0.038f + 0.168f;
	if (*prev != cur)
	{
		rect(menux_, cur * 0.038f + 0.168f, width_, 0.038f, 0, 0, 0, 200);
		if ((*prev == static_cast<int>(option_args_.size()) - 1) && cur == 0)
		{
			prevf = prevf - 0.009f;
			rect(menux_, prevf, width_, 0.038f, 255, 255, 255, 255);
			if (prevf <= curf)
			{
				prevf = curf;
				*prev = cur;
			}
		}
		if (prevf < curf)
		{
			if (prevf + 0.005f > curf)
				prevf = prevf + (curf - prevf);
			else
				prevf = prevf + 0.005f;
			rect(menux_, prevf, width_, 0.038f, 255, 255, 255, 255);
			if (prevf >= curf)
			{
				prevf = curf;
				*prev = cur;
			}
		}
		if (prevf > curf)
		{
			if (prevf - 0.005f < curf)
				prevf = prevf - (prevf - curf);
			prevf = prevf - 0.005f;
			rect(menux_, prevf, width_, 0.038f, 255, 255, 255, 255);
			if (prevf <= curf)
			{
				prevf = curf;
				*prev = cur;
			}
		}
	}
	else
	{
		*prev = cur;
		rect(menux_, cur * 0.038f + 0.168f, width_, 0.038f, 255, 255, 255, 255);
	}
}





