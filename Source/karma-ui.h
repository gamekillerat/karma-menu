#pragma once
// KARMA-UI.h - Author- Firah
#include "json.hpp"

class ingame_keyboard;
extern int current_frame;
extern bool visible;
using jsonf = nlohmann::json;

typedef struct
{
	std::string dict;
	std::string texture;
	int framecount;
	int delay = 25;
} gif_info;

typedef struct
{
	std::string dict;
	std::string texture;
} sprite_info;

typedef struct
{
	int open;
	int down;
	int up;
	int back;
	int left;
	int right;
	int select;
	int numpad_arrows_switch;
} menu_keys;

typedef struct
{
	std::string option, value;
	sprite_info sprite;
} extra_option_args;

typedef struct
{
	bool pressed;
	int key;
} key_info;

extern menu_keys keys_chosen;

class option
{
public:
	option(const std::string& option_text);
	option(const std::string& option_text, const std::string& submenu);
	option(const std::string& option_text, bool* boool);
	option(const std::string& option_text, int* innnt, int min = 0, int max = 10, int step = 1);
	option(const std::string& option_text, float* floaat, float min = 0.f, float max = 1.f, float step = 0.1f);
	option(const std::string& option_text, const std::vector<std::string>& string_vector, int* current_position);
	option(const std::string& option_text, const std::vector<std::string>& string_vector, int* current_position,
	       bool* booll);
	option(const std::string& option_text, const std::vector<std::string>& string_vector, int* current_position,
	       bool veh_spawner);
	option(const std::string& option_text, ingame_keyboard* keyboard);
	std::string get_text() const { return option_text_; }
	bool* get_bool() const { return bool_; }
	int* get_int() const { return int_; }
	float* get_float() const { return float_; }
	int get_mini() const { return mini_; }
	int get_maxi() const { return maxi_; }
	int get_stepi() const { return stepi_; }
	float get_minif() const { return minf_; }
	float get_maxf() const { return maxf_; }
	float get_stepf() const { return stepf_; }
	bool is_veh_vector() const { return spawner_; };
	ingame_keyboard* get_keyboard() const { return keyb_; }
	std::vector<std::string> get_vector() const { return string_vector_; }
	std::string get_submenu() const { return submenu_; }
	void set_bool_opposite() const { *bool_ ^= true; }
	void set_int(const int set_to) const { *int_ = set_to; }
	void set_float(const float set_to) const { *float_ = set_to; }

private:
	std::string option_text_;
	bool* bool_;
	int* int_;
	float* float_;
	int mini_;
	int maxi_;
	float minf_;
	float maxf_;
	int stepi_;
	float stepf_;
	bool spawner_;
	std::string submenu_;
	std::vector<std::string> string_vector_;
	ingame_keyboard* keyb_;
};


class KARMA
{
public:


	class menu
	{
	public:
		menu();

		typedef struct
		{
			bool current;
		} sub_args;

		void insert_sub(const std::string& menuname, const std::string& subtitle, const std::function<void()>& options) const;
		bool is_open() const;
		static void reset_scroller();
		void read_keys();
		void write_default_keys();
		void write_theme_defaults();
		void read_theme();
		void save_theme();
		void add_title(const std::string& title_str, bool globe = true) const;
		void add_title(const std::string& title_str, bool globe, sprite_info sprite) const;
		void set_main_title(const std::string& title_str) const;
		void clear_vars();
		void keys();
		void control_nav() const;
		static bool is_current_option_pressed();
		static bool is_current_option_pressed2();
		static bool is_current_option_selected();
		bool is_current_option_selected2();
		void clear_options() const;
		bool push_option(const option& args) const; // Regular Option
		bool push_option(const option* arguments) const;
		void nasty_scroll(int cur) const;
		static float get_text_width(const std::string& text, int font, float size);
		float right_align_text_coord(const std::string& text) const;
		void extra_title(const std::string& text);
		void extra_option(extra_option_args args);
		void end_extra_menu();
		void generate_json_language_template() const;
		//static void specify_var(Any Var, int OptionNumber);
		void render_options(); // Renders options put in the vector. (Auto done by push_option.)
		float conv360(float base, float min, float max) const;
		void check_keys(menu_keys keys);

		int get_current_option() const
		{
			return current_option_;
		}

		std::string get_current_menu() const
		{
			return current_menu_;
		}

		void set_current_menu(const int menu)
		{
			current_menu_ = menu;
		}

		int get_option_count()
		{
			return option_args_.size();
		}

		void clear_previous_menus()
		{
			previous_menus_.clear();
		}

		void render_globe(float x, float y, float sx, float sy, int r, int g, int b) const;
	private:
		static std::string current_menu_;
		float width_ = 0.255f;
		static float menux_;
		static bool visible_;
		static int current_option_;
		static std::vector<option> option_args_;
		static std::vector<std::string> previous_menus_;
		static std::string sub_string_;
		static std::string main_title_string_;
		static jsonf jsonlang_;
		static jsonf json_;
		static jsonf theme_json_;
		static jsonf login_json_;

	};
    static void in_game_img(const std::string& dict, const std::string& texture, float x, float y, float sx, float sy,
        int r,
        int g, int b, int a, float heading = 0.0f);
    static void str(const std::string& str, int font, float x, float y, float sx, float sy, int r,
        int g, int b, int a,
        bool outline = true, bool shadow = false, bool center = false);
private:
	static void rect(float x, float y, float sx, float sy, int r, int g, int b, int a);
};


static std::string thot_susername;
static std::string thot_spassword;

extern int TitleR;
extern int TitleG;
extern int TitleB;
extern int TitleA;
extern int ScrollerR;
extern int ScrollerG;
extern int ScrollerB;
extern int ScrollerA;
extern float ScrollerSpeed;
extern int OptionsR;
extern int OptionsG;
extern int OptionsB;
extern int OptionsA;
extern int NotSelectedOptionTextR;
extern int NotSelectedOptionTextG;
extern int NotSelectedOptionTextB;
extern int NotSelectedOptionTextA;
extern int SelectedOptionTextR;
extern int SelectedOptionTextG;
extern int SelectedOptionTextB;
extern int SelectedOptionTextA;
static std::string PictureSpriteDict;
static std::string PictureSpriteTexture;
