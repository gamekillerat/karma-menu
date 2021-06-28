/*
 * THE FILE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
 * CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
 * SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */
// KARMA-UI.cpp - Author- Firah
#include "stdafx.h"
#define NULL_FLOAT 0.0f
int previousmenu;
bool tenkeyless = false;
menu_keys keys_chosen = {
	VK_MULTIPLY,
	VK_NUMPAD2,
	VK_NUMPAD8,
	VK_NUMPAD0,
	VK_NUMPAD6,
	VK_NUMPAD4,
	VK_NUMPAD5,
	VK_F5
};
menu_keys arrow_keys;
menu_keys keys_backup;
jsonf KARMA::menu::theme_json_;
jsonf KARMA::menu::jsonlang_;
jsonf KARMA::menu::json_;
jsonf KARMA::menu::login_json_;
std::vector<std::string> nullvector{""};
std::vector<int> intnullv;
bool KARMA::menu::visible_ = false;
int KARMA::menu::current_option_ = 0;
float KARMA::menu::menux_ = 0.66f;
std::string KARMA::menu::current_menu_ = "Main";
std::vector<option> KARMA::menu::option_args_;
std::vector<std::string> KARMA::menu::previous_menus_;
std::string KARMA::menu::sub_string_ = "KARMA.";
std::string KARMA::menu::main_title_string_ = "KARMA.";
using namespace std;
option::option(const std::string& option_text)
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
	submenu_ = "";
	string_vector_ = {""};
	keyb_ = nullptr;
	spawner_ = NULL;
}

option::option(const std::string& option_text, const std::string& submenu)
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
	string_vector_ = {""};
	keyb_ = nullptr;
	spawner_ = NULL;
}


option::option(const std::string& option_text, bool* boool)
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
	submenu_ = "";
	string_vector_ = {""};
	keyb_ = nullptr;
	spawner_ = NULL;
}

option::option(const std::string& option_text, int* innnt, const int min, const int max, const int step)
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
	submenu_ = "";
	string_vector_ = {""};
	keyb_ = nullptr;
	spawner_ = NULL;
}

option::option(const std::string& option_text, float* floaat, const float min, const float max,
               const float step)
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
	submenu_ = "";
	string_vector_ = {""};
	keyb_ = nullptr;
	spawner_ = NULL;
}

option::option(const std::string& option_text, const std::vector<std::string>& string_vector,
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
	submenu_ = "";
	string_vector_ = string_vector;
	keyb_ = nullptr;
	spawner_ = NULL;
}

option::option(const std::string& option_text, const std::vector<std::string>& string_vector,
               int* current_position, bool* booll)
{
	option_text_ = option_text;
	bool_ = booll;
	int_ = current_position;
	float_ = nullptr;
	mini_ = 0;
	maxi_ = string_vector_.size();
	minf_ = NULL;
	maxf_ = NULL;
	stepi_ = 1;
	stepf_ = NULL;
	submenu_ = "";
	string_vector_ = string_vector;
	keyb_ = nullptr;
	spawner_ = NULL;
}

option::option(const std::string& option_text, const std::vector<std::string>& string_vector,
               int* current_position, const bool veh_spawner)
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
	submenu_ = "";
	string_vector_ = string_vector;
	keyb_ = nullptr;
	spawner_ = veh_spawner;
}

option::option(const std::string& option_text, ingame_keyboard* keyboard)
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
	submenu_ = "";
	string_vector_ = {""};
	keyb_ = keyboard;
	spawner_ = NULL;
}

int current_frame = 1;
KARMA::menu::menu()
= default;
std::map<std::string, std::vector<option>> menu_options;
std::vector<std::string> mapped_menus;

void KARMA::menu::insert_sub(const std::string& menuname, const std::string& subtitle,
                            const std::function<void()>& options) const
{
	if (visible_)
	{
		if (current_menu_ == menuname)
		{
			sub_string_ = subtitle;
			add_title(main_title_string_, true);
			options();
			menu_options[menuname] = option_args_;
		}
	}
}


bool KARMA::menu::is_open() const
{
	return visible_;
}


int titleticker = GetCurrentTime();
int gifdelay = 0;

void resettitleticker()
{
	titleticker = GetCurrentTime();
}

bool dd = false;
std::string spritestr;
char* string2;

float prevf;

void KARMA::menu::reset_scroller()
{
	current_option_ = 0;
}

void KARMA::menu::read_keys()
{
	/*const auto inif = new inifile();
	auto openkey = inif->read(".//Config//HotKeys.ini", "1", "Open");
	auto down = inif->read(".//Config//HotKeys.ini", "1", "Down");
	auto up = inif->read(".//Config//HotKeys.ini", "1", "Up");
	auto back = inif->read(".//Config//HotKeys.ini", "1", "Back");
	auto right = inif->read(".//Config//HotKeys.ini", "1", "Right");
	auto left = inif->read(".//Config//HotKeys.ini", "1", "Left");
	auto select = inif->read(".//Config//HotKeys.ini", "1", "Select");
	auto modeswich = inif->read(".//Config//HotKeys.ini", "1", "Control Switch");
	keys_backup = { openkey, down, up, back, right, left, select, modeswich };
	openkey = inif->read(".//Config//HotKeys.ini", "2", "Open");
	down = inif->read(".//Config//HotKeys.ini", "2", "Down");
	up = inif->read(".//Config//HotKeys.ini", "2", "Up");
	back = inif->read(".//Config//HotKeys.ini", "2", "Back");
	right = inif->read(".//Config//HotKeys.ini", "2", "Right");
	left = inif->read(".//Config//HotKeys.ini", "2", "Left");
	select = inif->read(".//Config//HotKeys.ini", "2", "Select");
	modeswich = inif->read(".//Config//HotKeys.ini", "2", "Control Switch");
	arrow_keys = { openkey, down, up, back, right, left, select, modeswich };
	delete inif;*/
	std::ifstream json_file("./KARMA/config.json");
	json_file >> json_;
	json_file.close();
	//thot_susername = json_["Login"]["Username"].get<std::string>();
	//thot_spassword = json_["Login"]["Password"].get<std::string>();
	keys_backup = {
		json_["HotKeys"]["Regular"]["Open"],
		json_["HotKeys"]["Regular"]["Down"],
		json_["HotKeys"]["Regular"]["Up"],
		json_["HotKeys"]["Regular"]["Back"],
		json_["HotKeys"]["Regular"]["Right"],
		json_["HotKeys"]["Regular"]["Left"],
		json_["HotKeys"]["Regular"]["Select"],
		json_["HotKeys"]["Regular"]["Switch Modes"]
	};
	arrow_keys = {
		json_["HotKeys"]["Alternate"]["Open"],
		json_["HotKeys"]["Alternate"]["Down"],
		json_["HotKeys"]["Alternate"]["Up"],
		json_["HotKeys"]["Alternate"]["Back"],
		json_["HotKeys"]["Alternate"]["Right"],
		json_["HotKeys"]["Alternate"]["Left"],
		json_["HotKeys"]["Alternate"]["Select"],
		json_["HotKeys"]["Alternate"]["Switch Modes"]
	};
}

void KARMA::menu::write_default_keys()
{
	//json_["Login"]["Username"] = "Not Set";
	//json_["Login"]["Password"] = "Not Set";
	json_["HotKeys"]["Regular"]["Open"] = VK_MULTIPLY;
	json_["HotKeys"]["Regular"]["Down"] = VK_NUMPAD2;
	json_["HotKeys"]["Regular"]["Up"] = VK_NUMPAD8;
	json_["HotKeys"]["Regular"]["Back"] = VK_NUMPAD0;
	json_["HotKeys"]["Regular"]["Right"] = VK_NUMPAD6;
	json_["HotKeys"]["Regular"]["Left"] = VK_NUMPAD4;
	json_["HotKeys"]["Regular"]["Select"] = VK_NUMPAD5;
	json_["HotKeys"]["Regular"]["Switch Modes"] = VK_F5;
	json_["HotKeys"]["Alternate"]["Open"] = VK_F4;
	json_["HotKeys"]["Alternate"]["Down"] = VK_DOWN;
	json_["HotKeys"]["Alternate"]["Up"] = VK_UP;
	json_["HotKeys"]["Alternate"]["Back"] = VK_BACK;
	json_["HotKeys"]["Alternate"]["Right"] = VK_RIGHT;
	json_["HotKeys"]["Alternate"]["Left"] = VK_LEFT;
	json_["HotKeys"]["Alternate"]["Select"] = VK_RETURN;
	json_["HotKeys"]["Alternate"]["Switch Modes"] = VK_F5;
	std::ofstream json_file("./KARMA/config.json");
	json_file << std::setw(4) << json_ << std::endl;
	json_file.close();
}




void KARMA::menu::write_theme_defaults()
{
	theme_json_["Theme"]["Title"]["R"] = 0;
	theme_json_["Theme"]["Title"]["G"] = 0;
	theme_json_["Theme"]["Title"]["B"] = 0;
	theme_json_["Theme"]["Title"]["A"] = 150;
	theme_json_["Theme"]["Scroller"]["R"] = 255;
	theme_json_["Theme"]["Scroller"]["G"] = 255;
	theme_json_["Theme"]["Scroller"]["B"] = 255;
	theme_json_["Theme"]["Scroller"]["A"] = 255;
	theme_json_["Theme"]["Scroller"]["Speed"] = 0.005f;
	theme_json_["Theme"]["Options"]["R"] = 0;
	theme_json_["Theme"]["Options"]["G"] = 0;
	theme_json_["Theme"]["Options"]["B"] = 0;
	theme_json_["Theme"]["Options"]["A"] = 150;
	theme_json_["Theme"]["Not Selected Option Text"]["R"] = 255;
	theme_json_["Theme"]["Not Selected Option Text"]["G"] = 255;
	theme_json_["Theme"]["Not Selected Option Text"]["B"] = 255;
	theme_json_["Theme"]["Not Selected Option Text"]["A"] = 255;
	theme_json_["Theme"]["Selected Option Text"]["R"] = 0;
	theme_json_["Theme"]["Selected Option Text"]["G"] = 0;
	theme_json_["Theme"]["Selected Option Text"]["B"] = 0;
	theme_json_["Theme"]["Selected Option Text"]["A"] = 255;
	std::ofstream json_file("./KARMA/theme.json");
	json_file << std::setw(4) << theme_json_ << std::endl;
	json_file.close();
}

int TitleR = 255;
int TitleG = 255;
int TitleB = 255;
int TitleA = 150;
int ScrollerR = 255;
int ScrollerG = 255;
int ScrollerB = 255;
int ScrollerA = 255;
float ScrollerSpeed = 0.005f;
int OptionsR = 0;
int OptionsG = 0;
int OptionsB = 0;
int OptionsA = 150;
int NotSelectedOptionTextR = 255;
int NotSelectedOptionTextG = 255;
int NotSelectedOptionTextB = 255;
int NotSelectedOptionTextA = 255;
int SelectedOptionTextR = 0;
int SelectedOptionTextG = 0;
int SelectedOptionTextB = 0;
int SelectedOptionTextA = 255;

void KARMA::menu::read_theme()
{
	std::ifstream json_file("./KARMA/theme.json");
	json_file >> theme_json_;
	json_file.close();
	TitleR = theme_json_["Theme"]["Title"]["R"];
	TitleG = theme_json_["Theme"]["Title"]["G"];
	TitleB = theme_json_["Theme"]["Title"]["B"];
	TitleA = theme_json_["Theme"]["Title"]["A"];
	ScrollerR = theme_json_["Theme"]["Scroller"]["R"];
	ScrollerG = theme_json_["Theme"]["Scroller"]["G"];
	ScrollerB = theme_json_["Theme"]["Scroller"]["B"];
	ScrollerA = theme_json_["Theme"]["Scroller"]["A"];
	ScrollerSpeed = theme_json_["Theme"]["Scroller"]["Speed"];
	OptionsR = theme_json_["Theme"]["Options"]["R"];
	OptionsG = theme_json_["Theme"]["Options"]["G"];
	OptionsB = theme_json_["Theme"]["Options"]["B"];
	OptionsA = theme_json_["Theme"]["Options"]["A"];
	NotSelectedOptionTextR = theme_json_["Theme"]["Not Selected Option Text"]["R"];
	NotSelectedOptionTextG = theme_json_["Theme"]["Not Selected Option Text"]["G"];
	NotSelectedOptionTextB = theme_json_["Theme"]["Not Selected Option Text"]["B"];
	NotSelectedOptionTextA = theme_json_["Theme"]["Not Selected Option Text"]["A"];
	SelectedOptionTextR = theme_json_["Theme"]["Selected Option Text"]["R"];
	SelectedOptionTextG = theme_json_["Theme"]["Selected Option Text"]["G"];
	SelectedOptionTextB = theme_json_["Theme"]["Selected Option Text"]["B"];
	SelectedOptionTextA = theme_json_["Theme"]["Selected Option Text"]["A"];
}

void KARMA::menu::save_theme()
{
	theme_json_["Theme"]["Title"]["R"] = TitleR;
	theme_json_["Theme"]["Title"]["G"] = TitleG;
	theme_json_["Theme"]["Title"]["B"] = TitleB;
	theme_json_["Theme"]["Title"]["A"] = TitleA;
	theme_json_["Theme"]["Scroller"]["R"] = ScrollerR;
	theme_json_["Theme"]["Scroller"]["G"] = ScrollerG;
	theme_json_["Theme"]["Scroller"]["B"] = ScrollerB;
	theme_json_["Theme"]["Scroller"]["A"] = ScrollerA;
	theme_json_["Theme"]["Scroller"]["Speed"] = ScrollerSpeed;
	theme_json_["Theme"]["Options"]["R"] = OptionsR;
	theme_json_["Theme"]["Options"]["G"] = OptionsG;
	theme_json_["Theme"]["Options"]["B"] = OptionsB;
	theme_json_["Theme"]["Options"]["A"] = OptionsA;
	theme_json_["Theme"]["Not Selected Option Text"]["R"] = NotSelectedOptionTextR;
	theme_json_["Theme"]["Not Selected Option Text"]["G"] = NotSelectedOptionTextG;
	theme_json_["Theme"]["Not Selected Option Text"]["B"] = NotSelectedOptionTextB;
	theme_json_["Theme"]["Not Selected Option Text"]["A"] = NotSelectedOptionTextA;
	theme_json_["Theme"]["Selected Option Text"]["R"] = SelectedOptionTextR;
	theme_json_["Theme"]["Selected Option Text"]["G"] = SelectedOptionTextG;
	theme_json_["Theme"]["Selected Option Text"]["B"] = SelectedOptionTextB;
	theme_json_["Theme"]["Selected Option Text"]["A"] = SelectedOptionTextA;
	std::ofstream json_file("./KARMA/theme.json");
	json_file << std::setw(4) << theme_json_ << std::endl;
	json_file.close();
}

void KARMA::menu::add_title(const std::string& title_str, const bool globe) const
{
	rect(menux_, 0.1f, width_, 0.1f, TitleR, TitleG, TitleB, TitleA);
	str(title_str, 1, menux_, 0.075f, 1.027f, 1.027f, 255, 255, 255, 255, false, true, true);
	if (globe)
		render_globe(menux_ + 0.384f, 0.539741f, width_ + 0.8868f, 1.08714f, 255, 255, 250);
}

void KARMA::menu::add_title(const std::string& title_str, const bool globe, const sprite_info sprite) const
{
	rect(menux_, 0.1f, width_, 0.1f, 153, 153, 102, 255);
	in_game_img(const_cast<char*>(sprite.dict.c_str()), const_cast<char*>(sprite.texture.c_str()), menux_, 0.1f, width_,
	            0.1f, TitleR, TitleG, TitleB, TitleA);
	str(title_str, 1, menux_, 0.075f, 1.027f, 1.027f, 255, 255, 255, 255, false, true, true);
	if (globe)
		render_globe(menux_ + 0.384f, 0.539741f, width_ + 0.8868f, 1.08714f, 255, 255, 255);
}


void KARMA::menu::set_main_title(const std::string& title_str) const
{
	main_title_string_ = title_str;
}


int ticker = GetCurrentTime();
int delay = 125;

void resettick()
{
	ticker = GetCurrentTime();
}

bool visible = false;

std::map<std::string, key_info> keys_map;
std::vector<int> pressed_keys;

bool key_press(const int key)
{
	return GetAsyncKeyState(key);
}

void KARMA::menu::check_keys(const menu_keys keys)
{
	keys_map["Open"] = {
		key_press(keys.open) || (controls::is_control_pressed(0, ControlPhoneRight) && controls::
			is_control_pressed(0, ControlJump)),
		keys.open
	};
	keys_map["Up"] = {key_press(keys.up) || controls::is_control_pressed(0, ControlPhoneUp), keys.up};
	keys_map["Down"] = {key_press(keys.down) || controls::is_control_pressed(0, ControlPhoneDown), keys.down};
	keys_map["Select"] = {key_press(keys.select) || controls::is_control_pressed(0, ControlFrontendAccept), keys.select};
	keys_map["Left"] = {key_press(keys.left) || controls::is_control_pressed(0, ControlPhoneLeft), keys.left};
	keys_map["Right"] = {key_press(keys.right) || controls::is_control_pressed(0, ControlPhoneRight), keys.right};
	keys_map["Back"] = {key_press(keys.back) || controls::is_control_pressed(0, ControlFrontendCancel), keys.back};
	keys_map["Switch Modes"] = {key_press(keys.numpad_arrows_switch), keys.numpad_arrows_switch};
	/* The Following is from Origins Base, all credit to dan as i cba to find all the actions to disable*/
	ui::hide_help_text_this_frame();
	cam::set_cinematic_button_active(0);
	ui::hide_hud_component_this_frame(10);
	ui::hide_hud_component_this_frame(6);
	ui::hide_hud_component_this_frame(7);
	ui::hide_hud_component_this_frame(9);
	ui::hide_hud_component_this_frame(8);

	controls::disable_control_action(2, ControlNextCamera, true);

	controls::disable_control_action(2, ControlPhone, true);
	controls::disable_control_action(2, ControlVehicleCinCam, true);

	controls::disable_control_action(2, ControlSelectCharacterMichael, true);
	controls::disable_control_action(2, ControlSelectCharacterFranklin, true);
	controls::disable_control_action(2, ControlSelectCharacterTrevor, true);
	controls::disable_control_action(2, ControlSelectCharacterMultiplayer, true);
	controls::disable_control_action(2, ControlCharacterWheel, true);

	controls::disable_control_action(2, ControlMeleeAttackLight, true);
	controls::disable_control_action(2, ControlMeleeAttackHeavy, true);
	controls::disable_control_action(2, ControlMeleeAttackAlternate, true);

	controls::disable_control_action(2, ControlMultiplayerInfo, true);
	controls::disable_control_action(2, ControlMapPointOfInterest, true);
}

void KARMA::menu::clear_vars()
{
	keys_map.clear();
}

int tick_i = GetCurrentTime();
int tickedel = 125;

void KARMA::menu::keys()
{
	if (static_cast<int>(GetCurrentTime()) - tick_i >= tickedel)
	{
		check_keys(keys_chosen);
		control_nav();
		tick_i = GetCurrentTime();
	}
}

void KARMA::menu::control_nav() const
{
	if (tenkeyless)
		keys_chosen = arrow_keys;
	else
		keys_chosen = keys_backup;

	if (keys_map["Switch Modes"].pressed)
	{
		tenkeyless ^= true;
	}
	if (keys_map["Open"].pressed)
	{
		visible_ ^= true;
		reset_scroller();
		if (visible_)
		{
			current_menu_ = "Main";
			current_option_ = 0;
		}
	}
	if (keys_map["Back"].pressed)
	{
		if (previous_menus_.empty())
			visible_ = false;
		else
		{
			current_menu_ = previous_menus_.back();
			previous_menus_.pop_back();
			reset_scroller();
		}
	}
	if (keys_map["Up"].pressed)
	{
		if (current_option_ >= 1)
			current_option_--;
		else
			current_option_ = option_args_.size() - 1;
	}
	if (keys_map["Down"].pressed)
	{
		if (current_option_ <= static_cast<int>(option_args_.size()) - 2)
			current_option_++;
		else
			current_option_ = 0;
	}
}

void KARMA::rect(const float x, const float y, const float sx, const float sy, const int r, const int g, const int b,
                const int a)
{
	graphics::draw_rect(x, y, sx, sy, r, g, b, a);
}

bool KARMA::menu::is_current_option_pressed()
{
	return static_cast<int>(option_args_.size()) == current_option_ && keys_map["Select"].pressed;
}

bool KARMA::menu::is_current_option_pressed2()
{
	return static_cast<int>(option_args_.size()) - 1 == current_option_ && keys_map["Select"].pressed;
}

bool KARMA::menu::is_current_option_selected()
{
	return static_cast<int>(option_args_.size()) == current_option_;
}

bool KARMA::menu::is_current_option_selected2()
{
	return static_cast<int>(option_args_.size() + 1) == current_option_;
}

bool KARMA::menu::push_option(const option& args) const
{
	if (args.get_int() != nullptr && args.get_vector() == nullvector && args.get_bool() != nullptr)
	{
		if (is_current_option_selected())
		{
			if (keys_map["Left"].pressed)
			{
				args.set_int(*args.get_int() + args.get_stepi());
				if (*args.get_int() >= args.get_maxi())
					args.set_int(args.get_mini());
			}
			if (keys_map["Right"].pressed)
			{
				args.set_int(*args.get_int() - args.get_stepi());
				if (*args.get_int() <= args.get_mini())
					args.set_int(args.get_maxi());
			}
		}
	}
	else if (args.get_int() != nullptr && args.get_vector() == nullvector)
	{
		if (is_current_option_selected())
		{
			if (keys_map["Left"].pressed)
			{
				args.set_int(*args.get_int() + args.get_stepi());
				if (*args.get_int() >= args.get_maxi())
					args.set_int(args.get_mini());
			}
			if (keys_map["Right"].pressed)
			{
				args.set_int(*args.get_int() - args.get_stepi());
				if (*args.get_int() <= args.get_mini())
					args.set_int(args.get_maxi());
			}
		}
	}
	else if (args.get_vector() != nullvector && args.get_int() != nullptr)
	{
		if (is_current_option_selected())
		{
			if (keys_map["Left"].pressed)
			{
				args.set_int(*args.get_int() + 1);
				if (*args.get_int() >= static_cast<int>(args.get_vector().size()))
					args.set_int(0);
			}
			if (keys_map["Right"].pressed)
			{
				args.set_int(*args.get_int() - 1);
				if (*args.get_int() < 0)
					args.set_int(static_cast<int>(args.get_vector().size()) - 1);
			}
		}
	}
	else if (args.get_int() != nullptr)
	{
		if (is_current_option_selected())
		{
			if (keys_map["Left"].pressed)
			{
				args.set_int(*args.get_int() + 1);
				if (*args.get_int() >= 255)
					args.set_int(0);
			}
			if (keys_map["Right"].pressed)
			{
				args.set_int(*args.get_int() - 1);
				if (*args.get_int() <= 0)
					args.set_int(255);
			}
		}
	}
	else if (args.get_keyboard() != nullptr)
	{
		if (is_current_option_pressed())
		{
			args.get_keyboard()->start();
		}
		delete args.get_keyboard();
	}
	else if (args.get_bool() != nullptr)
	{
		if (is_current_option_pressed())
		{
			args.set_bool_opposite();
		}
	}
	else if (args.get_float() != nullptr)
	{
		if (is_current_option_selected())
		{
			if (keys_map["Left"].pressed)
			{
				args.set_float(*args.get_float() + args.get_stepf());
				if (*args.get_float() >= args.get_maxf())
					args.set_float(args.get_minif());
			}
			if (keys_map["Right"].pressed)
			{
				args.set_float(*args.get_float() - args.get_stepf());
				if (*args.get_float() <= args.get_minif())
					args.set_float(args.get_maxf());
			}
		}
	}

	else if (!args.get_submenu().empty())
	{
		if (is_current_option_pressed())
		{
			previous_menus_.push_back(current_menu_);
			clear_options();
			current_menu_ = args.get_submenu();
			reset_scroller();
		}
	}

	option_args_.push_back(args);
	return is_current_option_pressed2();
}

bool KARMA::menu::push_option(const option* arguments) const
{
	if (arguments->get_int() != nullptr && arguments->get_vector() == nullvector && arguments->get_bool() != nullptr)
	{
		if (is_current_option_selected())
		{
			if (keys_map["Left"].pressed)
			{
				arguments->set_int(*arguments->get_int() + 1);
				if (*arguments->get_int() >= static_cast<int>(arguments->get_vector().size()))
					arguments->set_int(0);
			}
			if (keys_map["Right"].pressed)
			{
				arguments->set_int(*arguments->get_int() - 1);
				if (*arguments->get_int() < 0)
					arguments->set_int(static_cast<int>(arguments->get_vector().size()) - 1);
			}
		}
		if (is_current_option_pressed())
			arguments->set_bool_opposite();
	}
	else if (arguments->get_int() != nullptr && arguments->get_vector() == nullvector)
	{
		if (is_current_option_selected())
		{
			if (keys_map["Left"].pressed)
			{
				arguments->set_int(*arguments->get_int() + arguments->get_stepi());
				if (*arguments->get_int() >= arguments->get_maxi())
					arguments->set_int(arguments->get_mini());
			}
			if (keys_map["Right"].pressed)
			{
				arguments->set_int(*arguments->get_int() - arguments->get_stepi());
				if (*arguments->get_int() <= arguments->get_mini())
					arguments->set_int(arguments->get_maxi());
			}
		}
	}
	else if (arguments->get_keyboard() != nullptr)
	{
		if (is_current_option_pressed())
		{
			arguments->get_keyboard()->start();
			delete arguments->get_keyboard();
		}
	}
	else if (arguments->get_bool() != nullptr)
	{
		if (is_current_option_pressed())
		{
			arguments->set_bool_opposite();
		}
	}
	else if (arguments->get_float() != nullptr)
	{
		if (is_current_option_selected())
		{
			if (keys_map["Left"].pressed)
			{
				arguments->set_float(*arguments->get_float() + arguments->get_stepf());
				if (*arguments->get_float() >= arguments->get_maxf())
					arguments->set_float(arguments->get_minif());
			}
			if (keys_map["Right"].pressed)
			{
				arguments->set_float(*arguments->get_float() - arguments->get_stepf());
				if (*arguments->get_float() <= arguments->get_minif())
					arguments->set_float(arguments->get_maxf());
			}
		}
	}
	else if (arguments->get_int() != nullptr)
	{
		if (is_current_option_selected())
		{
			if (keys_map["Left"].pressed)
			{
				arguments->set_int(*arguments->get_int() + arguments->get_stepi());
				if (*arguments->get_int() >= arguments->get_maxi())
					arguments->set_int(arguments->get_mini());
			}
			if (keys_map["Right"].pressed)
			{
				arguments->set_int(*arguments->get_int() - arguments->get_stepi());
				if (*arguments->get_int() <= arguments->get_mini())
					arguments->set_int(arguments->get_maxi());
			}
		}
	}
	else if (!arguments->get_submenu().empty())
	{
		if (is_current_option_pressed())
		{
			previous_menus_.push_back(current_menu_);
			reset_scroller();
			clear_options();
			current_menu_ = arguments->get_submenu();
		}
	}
	else if (arguments->get_vector() != nullvector && arguments->get_int() != nullptr)
	{
		if (is_current_option_selected())
		{
			if (keys_map["Left"].pressed)
			{
				arguments->set_int(*arguments->get_int() + 1);
				if (*arguments->get_int() >= static_cast<int>(arguments->get_vector().size()))
					arguments->set_int(0);
			}
			if (keys_map["Right"].pressed)
			{
				arguments->set_int(*arguments->get_int() - 1);
				if (*arguments->get_int() < 0)
					arguments->set_int(static_cast<int>(arguments->get_vector().size()) - 1);
			}
		}
	}
	option_args_.push_back(*arguments);
	delete arguments;
	return is_current_option_pressed2();
}

void KARMA::str(const std::string& str, const int font, const float x, const float y, const float sx, const float sy,
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

void KARMA::in_game_img(const std::string& dict, const std::string& texture, const float x, const float y,
                       const float sx, const float sy,
                       const int r, const int g, const int b, const int a, const float heading)
{
	if (!graphics::has_streamed_texture_dict_loaded(const_cast<char*>(dict.c_str())))
	{
		graphics::request_streamed_texture_dict(const_cast<char*>(dict.c_str()), false);
	}
	else
	{
		graphics::draw_sprite(const_cast<char*>(dict.c_str()), const_cast<char*>(texture.c_str()), x, y, sx, sy, heading, r,
		                      g, b, a);
	}
}

float KARMA::menu::get_text_width(const std::string& text, const int font, const float size)
{
	ui::_begin_text_command_width(static_cast<char*>("STRING"));
	ui::set_text_font(font);
	ui::set_text_scale(size, size);
	ui::add_text_component_substring_player_name(const_cast<char*>(text.c_str()));
	return ui::_end_text_command_get_width(true);
}

float KARMA::menu::right_align_text_coord(const std::string& text) const
{
	return menux_ + width_ / 2.f - get_text_width(text, 0, 0.35f);
}

void KARMA::menu::extra_title(const std::string& text)
{
#ifdef STYLO
	in_game_img(PictureSpriteDict, PictureSpriteTexture ,menux_ - 0.205f, 0.075f, width_ - 0.1f, 0.05f, TitleR, TitleG, TitleB, TitleA);
#else
	rect(menux_ - 0.205f, 0.075f, width_ - 0.1f, 0.05f, TitleR, TitleG, TitleB, TitleA);
#endif

	str(text, 1, menux_ - 0.205f, 0.06f, 0.6, 0.6, 255, 255, 255, 255, false, false, true);
}

std::vector<std::string> exoptions;

void KARMA::menu::extra_option(const extra_option_args args)
{
	exoptions.push_back(args.option);
	rect(menux_ - 0.205f, exoptions.size() * 0.02f + 0.09f, width_ - 0.1f, 0.02f, OptionsR, OptionsG, OptionsB, OptionsA);
	str(args.option + ": " + args.value, 0, menux_ - 0.27f, exoptions.size() * 0.02f + 0.079f, 0.3, 0.3,
	    NotSelectedOptionTextR, NotSelectedOptionTextG, NotSelectedOptionTextB,
	    NotSelectedOptionTextA, false, false, false);
	in_game_img(args.sprite.dict, args.sprite.texture, menux_ - 0.2755f, exoptions.size() * 0.02f + 0.09f, 0.013f, 0.0175f,
	            255, 255, 255, 255);
}

void KARMA::menu::end_extra_menu()
{
	//rect(menux_ - 0.205f, exoptions.size()* 0.02f + 0.09f, width_ - 0.1f, 0.02f, 0, 0, 0, 155);
#ifdef STYLO
	in_game_img(PictureSpriteDict, PictureSpriteTexture, menux_ - 0.205f, (exoptions.size() + 1) * 0.02f + 0.09f,
	            width_ - 0.1f, 0.02f, 255, 255, 255, 255);
#else
	rect(menux_ - 0.205f, (exoptions.size() + 1) * 0.02f + 0.09f,
	     width_ - 0.1f, 0.02f, TitleR, TitleG, TitleB, TitleA);
#endif
}

void KARMA::menu::generate_json_language_template() const
{
	for (auto i = 0; i < static_cast<int>(mapped_menus.size()); i++)
	{
		for (auto j = 2; i <= static_cast<int>(menu_options[mapped_menus[i]].size()); ++j)
		{
			jsonlang_[mapped_menus[i]][menu_options[mapped_menus[i]][j].get_text()] = menu_options[mapped_menus[i]][j].
				get_text();

			std::ofstream json_file("./KARMA/lang/default.json");
			json_file << std::setw(4) << jsonlang_ << std::endl;
			json_file.close();
		}
	}

	//free memory
	mapped_menus.clear();
	menu_options.clear();
	///eadmenusforlangjson = false;
}

void KARMA::menu::clear_options() const
{
	option_args_.clear();
	exoptions.clear();
}

void KARMA::menu::render_options()
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
			nasty_scroll(j);
			
			if (option_args_[i].get_int() != nullptr && option_args_[i].get_vector() == nullvector)
			{
				stringstream ss;
				ss << *option_args_[i].get_int();
				stringstream ss2;
				ss2 << option_args_[i].get_maxi();
				const auto fltstr = "< " + ss.str() + " > / " + ss2.str();
				str(fltstr, 0, right_align_text_coord(fltstr), j * 0.038f + 0.155f, 0.35f, 0.35f, SelectedOptionTextR,
				    SelectedOptionTextG, SelectedOptionTextB, SelectedOptionTextA, false, false,
				    false);
			}
			else if (option_args_[i].get_float() != nullptr)
			{
			    std::stringstream ss;
				ss << *option_args_[i].get_float();
			    std::stringstream ss2;
				ss2 << option_args_[i].get_maxf();
				const auto fltstr = "< " + ss.str() + " > / " + ss2.str();
				str(fltstr, 0, right_align_text_coord(fltstr), j * 0.038f + 0.155f, 0.35f, 0.35f, SelectedOptionTextR,
				    SelectedOptionTextG, SelectedOptionTextB, SelectedOptionTextA, false, false,
				    false);
			}
			else if (!option_args_[i].get_submenu().empty())
			{
				const auto submenustr = ">>";
				str(submenustr, 0, right_align_text_coord(submenustr), j * 0.038f + 0.155f, 0.35f, 0.35f, SelectedOptionTextR,
				    SelectedOptionTextG, SelectedOptionTextB, SelectedOptionTextA, false,
				    false, false);
			}
			else if (option_args_[i].get_bool() != nullptr)
			{
				in_game_img(static_cast<char*>("shared"),
				            *option_args_[i].get_bool() ? static_cast<char*>("medaldot_32") : static_cast<char*>("emptydot_32"),
				            menux_ + 0.12f,
				            j * 0.038f + 0.168f, 0.02f, 0.04f, SelectedOptionTextR, SelectedOptionTextG, SelectedOptionTextB,
				            SelectedOptionTextA);
			}
			else if (option_args_[i].get_vector() != nullvector && option_args_[i].get_int() != nullptr)
			{
				const auto countint = *option_args_[i].get_int() + 1;
				stringstream ss;
				ss << countint;
				stringstream ss2;
				ss2 << static_cast<int>(option_args_[i].get_vector().size());
				const auto fltstr = "[" + option_args_[i].get_vector()[*option_args_[i].get_int()] + "]" + "~c~ (" + ss.str() +
					" / " + ss2.str() + ")";
				str(fltstr, 0, right_align_text_coord(fltstr), j * 0.038f + 0.155f, 0.35f, 0.35f, SelectedOptionTextR,
				    SelectedOptionTextG, SelectedOptionTextB, SelectedOptionTextA, false, false,
				    false);
			}
			str(option_args_[i].get_text(), 0, menux_ - 0.123f, j * 0.038f + 0.155f, 0.35f, 0.35f, SelectedOptionTextR,
			    SelectedOptionTextG, SelectedOptionTextB, SelectedOptionTextA, false, false,
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
				str(fltstr, 0, right_align_text_coord(fltstr), j * 0.038f + 0.155f, 0.35f, 0.35f, NotSelectedOptionTextR,
				    NotSelectedOptionTextG, NotSelectedOptionTextB, NotSelectedOptionTextA, false, false,
				    false);
			}

			else if (option_args_[i].get_float() != nullptr)
			{
				stringstream ss;
				ss << *option_args_[i].get_float();
				stringstream ss2;
				ss2 << option_args_[i].get_maxf();
				const auto fltstr = "< " + ss.str() + " > / " + ss2.str();
				str(fltstr, 0, right_align_text_coord(fltstr), j * 0.038f + 0.155f, 0.35f, 0.35f, NotSelectedOptionTextR,
				    NotSelectedOptionTextG, NotSelectedOptionTextB, NotSelectedOptionTextA, false, false,
				    false);
			}
			else if (!option_args_[i].get_submenu().empty())
			{
				const auto submenustr = ">>";
				str(submenustr, 0, right_align_text_coord(submenustr), j * 0.038f + 0.155f, 0.35f, 0.35f, NotSelectedOptionTextR,
				    NotSelectedOptionTextG, NotSelectedOptionTextB, NotSelectedOptionTextA, false,
				    false, false);
			}
			else if (option_args_[i].get_vector() != nullvector && option_args_[i].get_int() != nullptr)
			{
				const auto countint = *option_args_[i].get_int() + 1;
				stringstream ss;
				ss << countint;
				stringstream ss2;
				ss2 << static_cast<int>(option_args_[i].get_vector().size());
				const auto fltstr = "[" + option_args_[i].get_vector()[*option_args_[i].get_int()] + "]" + "~c~ (" + ss.str() +
					" / " + ss2.str() + ")";
				str(fltstr, 0, right_align_text_coord(fltstr), j * 0.038f + 0.155f, 0.35f, 0.35f, NotSelectedOptionTextR,
				    NotSelectedOptionTextG, NotSelectedOptionTextB, NotSelectedOptionTextA, false, false,
				    false);
			}
			else if (option_args_[i].get_bool() != nullptr)
			{
				graphics::_set_2d_layer(8);
				in_game_img(static_cast<char*>("shared"),
				            *option_args_[i].get_bool() ? static_cast<char*>("medaldot_32") : static_cast<char*>("emptydot_32"),
				            menux_ + 0.12f,
				            j * 0.038f + 0.168f, 0.02f, 0.04f, NotSelectedOptionTextR, NotSelectedOptionTextG,
				            NotSelectedOptionTextB, NotSelectedOptionTextA);
			}
			graphics::_set_2d_layer(1);
			rect(menux_, j * 0.038f + 0.168f, width_, 0.038f, OptionsR, OptionsG, OptionsG, OptionsA);
			str(option_args_[i].get_text(), 0, menux_ - 0.123f, j * 0.038f + 0.155f, 0.35f, 0.35f, NotSelectedOptionTextR,
			    NotSelectedOptionTextG, NotSelectedOptionTextB, NotSelectedOptionTextA, false,
			    false,
			    false);
		}
	}
#ifdef STYLO
	in_game_img(PictureSpriteDict, PictureSpriteTexture, menux_,
	            (option_args_.size() > 16 ? 16 : option_args_.size()) * 0.038f + 0.168f, width_, 0.038f, TitleR, TitleG, TitleB, TitleA, 0.0f);
#else
	rect(menux_,
	     (option_args_.size() > 16 ? 16 : option_args_.size()) * 0.038f + 0.168f, width_, 0.038f, TitleR, TitleG, TitleB,
	     TitleA);
#endif
	str(sub_string_, 1, menux_ - 0.123f, (option_args_.size() > 16 ? 16 : option_args_.size()) * 0.038f + 0.155f, 0.43f,
	    0.43f, 255, 255, 255, 255, false, false,
	    false);
}


float KARMA::menu::conv360(float base, const float min, const float max) const
{
	if (min == max) return min;
	const auto f_var0 = max - min;
	base -= round(base - min / f_var0) * f_var0;
	if (base < min) base += f_var0;
	return base;
}

void KARMA::menu::render_globe(const float x, const float y, const float sx, const float sy, const int r, const int g,
                              const int b) const
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
	//graphics::set_scaleform_movie_as_no_longer_needed(&g_glare_handle);
}

void KARMA::menu::nasty_scroll(const int cur) const
{

	rect(menux_, cur * 0.038f + 0.168f, width_, 0.038f, ScrollerR, ScrollerG, ScrollerB, ScrollerA);
}
