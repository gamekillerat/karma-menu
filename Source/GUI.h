#pragma once
#include "stdafx.h"
#include <string>
#include <vector>
extern int current_frame;


class guac
{
public:
	class option_args
	{
	public:
		option_args(const std::string& option_text);
		option_args(const std::string& option_text, int submenu);
		option_args(const std::string& option_text, bool * boool);
		option_args(const std::string& option_text, int * innnt, int min = 0, int max = 10, int step = 0);
		option_args(const std::string& option_text, float* floaat, float min = 0.f, float max = 1.f, float step = 0.1f);
		option_args(const std::string& option_text, const std::vector<std::string>& string_vector, int * current_position);
		std::string get_text() const { return option_text_; }
		bool * get_bool() const { return bool_; }
		int * get_int() const { return int_; }
		float * get_float() const { return float_; }
		int get_mini() const { return mini_; }
		int get_maxi() const { return maxi_; }
		int get_stepi() const { return stepi_; }
		float get_minif() const { return minf_; }
		float get_maxf() const { return maxf_; }
		float get_stepf() const { return stepf_; }
		std::vector<std::string> get_vector() const { return string_vector_; }
		float get_submenu() const { return submenu_; }
		void set_bool_opposite() const { *bool_ ^= true; }
		void set_int(const int set_to) const { *int_ = set_to; }
		void set_float(const float set_to) const { *float_ = set_to; }


	private:
		std::string option_text_;
		bool * bool_;
		int * int_;
		float * float_;
		int mini_;
		int maxi_;
		float minf_;
		float maxf_;
		int stepi_;
		float stepf_;
		int submenu_;
		std::vector<std::string> string_vector_;
	};

	class menu
	{
	public:
		menu();

		static bool is_open();
		static void add_title(const std::string& title_str, bool globe = true);
		static void add_subtitle(const std::string& title_str);
		static void clear_vars();
		static void clear_options();
		static void reset_scroller();
		static void check_keys();
		static bool is_current_option_pressed();
		static bool is_current_option_pressed2();
		static bool is_current_option_selected();
		static bool push_option(const option_args& args); // Regular Option
		static bool push_option(const option_args * args);
		static void nasty_scroll(int* prev, int cur);
		static float get_text_width(const std::string& text, const int font, const float size);
		static float right_align_text_coord(const std::string& text);
		//static void specify_var(Any Var, int OptionNumber);
		static void render_options(); // Renders options put in the vector. (Auto done by push_option.)
		static int get_current_option()
		{
			return current_option_;
		}
		static int current_menu_;
		static void render_globe(float x, float y, float sx, float sy, int r, int g, int b);
		//static void check_keys();
	private:
		static float right_margin_;
		static std::string subtitlen;
		static float width_;
		static float menux_;
		static int option_count_;
		static bool visible_;
		static int current_option_;
		static int previous_option_;
		static bool option_pressed_;
		static bool left_pressed_;
		static bool right_pressed_;
		static float conv360(float base, float min, float max);
		static std::vector<option_args> option_args_;
		static std::vector<int> previous_menus_;
	};


private:
	static void rect(float x, float y, float sx, float sy, int r, int g, int b, int a);
	static void str(const std::string& str, const int font, const float x, const float y, const float sx, const float sy, const int r, const
		int g, const int b, const int a,
		const bool outline = true, const bool shadow = false, const bool center = false);
	static void in_game_img(char* dict, char* texture, const float x, const float y, const float sx, const float sy, const int r, const int g, const
		int b, const int a, float heading = 0.0f);
};

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


