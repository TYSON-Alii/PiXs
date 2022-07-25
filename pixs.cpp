#include <Windows.h>
#include <XsGL.hpp>
#include <glm.hpp>
#include <ext.hpp>
using glm::mat4;
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include <imgui.h>
#include <imgui-SFML.h>
#include <imgui_stdlib.h>
namespace im = ImGui;
#include <GLM-Vex.hpp>
#include <Vex.hpp>
#define STB_IMAGE_IMPLEMENTATION
#include <librarys/stb.h>
#include <librarys/stb_image.h>
#include <Utilityx.hpp>
#undef then
#undef end
#undef in
#undef temp
#undef none
#undef None
#undef near
#undef far
#define AppName "PiXs"
const vex3ub Red = vex3ub(248, 29, 67);
const vex3ub DarkGreen = vex3ub(0, 98, 67);
const vex3ub Blue = vex3ub(0, 179, 233);
const vex3ub Pink = vex3ub(255, 221, 227);
const vex3ub DarkBlue = vex3ub(91, 73, 226);
const vex3ub Grey = vex3ub(58, 57, 73);
const vex3ub Purple = vex3ub(143, 10, 165);
const vex3ub LightPurple = vex3ub(146, 112, 218);
const vex3ub Orange = vex3ub(255, 91, 23);
const vex3ub Yellow = vex3ub(232, 255, 53);
const vex3ub Lime = vex3ub(140, 229, 15);
void StyleDark() {
	ImVec4* colors = ImGui::GetStyle().Colors;
	colors[ImGuiCol_Text] = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
	colors[ImGuiCol_TextDisabled] = ImVec4(0.50f, 0.50f, 0.50f, 1.00f);
	colors[ImGuiCol_WindowBg] = ImVec4(0.10f, 0.10f, 0.10f, 0.28f);
	colors[ImGuiCol_ChildBg] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
	colors[ImGuiCol_PopupBg] = ImVec4(0.19f, 0.19f, 0.19f, 0.92f);
	colors[ImGuiCol_Border] = ImVec4(0.19f, 0.19f, 0.19f, 0.29f);
	colors[ImGuiCol_BorderShadow] = ImVec4(0.00f, 0.00f, 0.00f, 0.24f);
	colors[ImGuiCol_FrameBg] = ImVec4(0.05f, 0.05f, 0.05f, 0.54f);
	colors[ImGuiCol_FrameBgHovered] = ImVec4(0.19f, 0.19f, 0.19f, 0.54f);
	colors[ImGuiCol_FrameBgActive] = ImVec4(0.20f, 0.22f, 0.23f, 1.00f);
	colors[ImGuiCol_TitleBg] = ImVec4(0.06f, 0.06f, 0.06f, 1.00f);
	colors[ImGuiCol_TitleBgActive] = ImVec4(0.06f, 0.06f, 0.06f, 1.00f);
	colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0.06f, 0.06f, 0.06f, 1.00f);
	colors[ImGuiCol_MenuBarBg] = ImVec4(0.06f, 0.06f, 0.06f, 1.00f);
	colors[ImGuiCol_ScrollbarBg] = ImVec4(0.05f, 0.05f, 0.05f, 0.54f);
	colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.34f, 0.34f, 0.34f, 0.54f);
	colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.40f, 0.40f, 0.40f, 0.54f);
	colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.56f, 0.56f, 0.56f, 0.54f);
	colors[ImGuiCol_CheckMark] = ImVec4(0.89f, 0.46f, 0.54f, 1.00f);
	colors[ImGuiCol_SliderGrab] = ImVec4(0.34f, 0.34f, 0.34f, 0.54f);
	colors[ImGuiCol_SliderGrabActive] = ImVec4(0.56f, 0.56f, 0.56f, 0.54f);
	colors[ImGuiCol_Button] = ImVec4(0.05f, 0.05f, 0.05f, 0.54f);
	colors[ImGuiCol_ButtonHovered] = ImVec4(0.19f, 0.19f, 0.19f, 0.54f);
	colors[ImGuiCol_ButtonActive] = ImVec4(0.20f, 0.22f, 0.23f, 1.00f);
	colors[ImGuiCol_Header] = ImVec4(0.00f, 0.00f, 0.00f, 0.52f);
	colors[ImGuiCol_HeaderHovered] = ImVec4(0.00f, 0.00f, 0.00f, 0.36f);
	colors[ImGuiCol_HeaderActive] = ImVec4(0.20f, 0.22f, 0.23f, 0.33f);
	colors[ImGuiCol_Separator] = ImVec4(0.28f, 0.28f, 0.28f, 0.29f);
	colors[ImGuiCol_SeparatorHovered] = ImVec4(0.44f, 0.44f, 0.44f, 0.29f);
	colors[ImGuiCol_SeparatorActive] = ImVec4(0.40f, 0.44f, 0.47f, 1.00f);
	colors[ImGuiCol_ResizeGrip] = ImVec4(0.f, 0.f, 0.f, 0.f);
	colors[ImGuiCol_ResizeGripHovered] = ImVec4(0.f, 0.f, 0.f, 0.f);
	colors[ImGuiCol_ResizeGripActive] = ImVec4(0.f, 0.f, 0.f, 0.f);
	colors[ImGuiCol_Tab] = ImVec4(0.00f, 0.00f, 0.00f, 0.52f);
	colors[ImGuiCol_TabHovered] = ImVec4(0.14f, 0.14f, 0.14f, 1.00f);
	colors[ImGuiCol_TabActive] = ImVec4(0.20f, 0.20f, 0.20f, 0.36f);
	colors[ImGuiCol_TabUnfocused] = ImVec4(0.00f, 0.00f, 0.00f, 0.52f);
	colors[ImGuiCol_TabUnfocusedActive] = ImVec4(0.14f, 0.14f, 0.14f, 1.00f);
	colors[ImGuiCol_PlotLines] = ImVec4(1.00f, 0.00f, 0.00f, 1.00f);
	colors[ImGuiCol_PlotLinesHovered] = ImVec4(1.00f, 0.00f, 0.00f, 1.00f);
	colors[ImGuiCol_PlotHistogram] = ImVec4(1.00f, 0.00f, 0.00f, 1.00f);
	colors[ImGuiCol_PlotHistogramHovered] = ImVec4(1.00f, 0.00f, 0.00f, 1.00f);
	colors[ImGuiCol_TableHeaderBg] = ImVec4(0.00f, 0.00f, 0.00f, 0.52f);
	colors[ImGuiCol_TableBorderStrong] = ImVec4(0.00f, 0.00f, 0.00f, 0.52f);
	colors[ImGuiCol_TableBorderLight] = ImVec4(0.28f, 0.28f, 0.28f, 0.29f);
	colors[ImGuiCol_TableRowBg] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
	colors[ImGuiCol_TableRowBgAlt] = ImVec4(1.00f, 1.00f, 1.00f, 0.06f);
	colors[ImGuiCol_TextSelectedBg] = ImVec4(0.20f, 0.22f, 0.23f, 1.00f);
	colors[ImGuiCol_DragDropTarget] = ImVec4(0.33f, 0.67f, 0.86f, 1.00f);
	colors[ImGuiCol_NavHighlight] = ImVec4(1.00f, 0.00f, 0.00f, 1.00f);
	colors[ImGuiCol_NavWindowingHighlight] = ImVec4(1.00f, 0.00f, 0.00f, 0.70f);
	colors[ImGuiCol_NavWindowingDimBg] = ImVec4(1.00f, 0.00f, 0.00f, 0.20f);
	colors[ImGuiCol_ModalWindowDimBg] = ImVec4(0.5f, 0.5f, 0.5f, 0.01f);

	ImGuiStyle& style = ImGui::GetStyle();
	style.WindowPadding = ImVec2(8.00f, 8.00f);
	style.FramePadding = ImVec2(5.00f, 2.00f);
	style.CellPadding = ImVec2(6.00f, 6.00f);
	style.ItemSpacing = ImVec2(6.00f, 6.00f);
	style.ItemInnerSpacing = ImVec2(6.00f, 6.00f);
	style.TouchExtraPadding = ImVec2(0.00f, 0.00f);
	style.IndentSpacing = 10;
	style.ScrollbarSize = 11;
	style.GrabMinSize = 10;
	style.WindowBorderSize = 1;
	style.ChildBorderSize = 1;
	style.PopupBorderSize = 1;
	style.FrameBorderSize = 1;
	style.TabBorderSize = 1;
	style.WindowRounding = 0;
	style.ChildRounding = 0;
	style.FrameRounding = 3;
	style.PopupRounding = 3;
	style.ScrollbarRounding = 0;
	style.GrabRounding = 3;
	style.LogSliderDeadzone = 4;
	style.TabRounding = 3;
};
struct {
	inline static vex2i Pos() {
		POINT p;
		GetCursorPos(&p);
		return vex2i(p.x, p.y);
	};
	enum class Button_t : byte {
		Left = 1,
		Right = 2,
		Middle = 16
	};
	using enum Button_t;
	inline static bool Pressed() { return (GetKeyState((int)Button_t::Left) & 0x800) or (GetKeyState((int)Button_t::Right) & 0x800) or (GetKeyState((int)Button_t::Middle) & 0x800); };
} Mouse;
struct {
	enum class Key_t : byte {
		A = 65, B = 66, C = 67, D = 68, E = 69, F = 70, G = 71, H = 72, I = 73, J = 74, K = 75, L = 76, M = 77, N = 78, O = 79, P = 80, Q = 81, R = 82, S = 83, T = 84, U = 85, V = 86, W = 87, X = 88, Y = 89, Z = 90,
		Num0 = 48, Num1 = 49, Num2 = 50, Num3 = 51, Num4 = 52, Num5 = 53, Num6 = 54, Num7 = 55, Num8 = 56, Num9 = 57,
		Space = 32,
		Escape = 27,
		Delete = 8,
		Tab = 9,
		Up = 38,
		Down = 40,
		Right = 39,
		Left = 37,
		Shift = 16,
		Enter = 13
	};
	using enum Key_t;
	inline bool Pressed(const Key_t& key) { return (GetKeyState((int)key) & 0x800); }
	inline bool Pressed(const decltype(Mouse)::Button_t& key) { return (GetKeyState((int)key) & 0x800); }
} Key;
class Camera {
public:
	Camera() = default;
	vex2f pos = 0.f;
	f32 zoom = 1.f;
	auto matrix(const auto& viewport) const {
		return
			glm::ortho(0.f, (f32)viewport.x, 0.f, (f32)viewport.y) *
			glm::translate(glm::mat4(1.0f), glm::vec3(-pos.x, -pos.y, 0)) *
			glm::scale(glm::mat4(1.0f), glm::vec3(zoom));
	}
};
sf::RenderWindow Window;
sf::Event Event;
Camera Cam;
vex3f BgColor = 0.f;
ImVec4* them;
void draw();
sf::Texture tex_brush, tex_picker, tex_eraser, tex_fill, tex_quad, tex_quadf, tex_checker, tex_swap, tex_line, tex_lchecker, tex_lgradient;
void init_tex(uint& id, auto data) {
	glGenTextures(1, &id);
	glBindTexture(GL_TEXTURE_2D, id);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, 16, 16, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
	glBindTexture(GL_TEXTURE_2D, 0);
}
void init() {
	Cam.pos = vex2f(-600, -350);
	ShowWindow(GetConsoleWindow(), 0);
	Window.create(sf::VideoMode(1200, 750), AppName, sf::Style::Default, sf::ContextSettings(24, 8, 0, 3, 3, 0, false));
	Window.setActive(true);
	ImGui::SFML::Init(Window);
	ImGuiIO& io = ImGui::GetIO();
	auto font_mario = io.Fonts->AddFontFromFileTTF("Mario-Kart-DS.ttf", 16.0f);
	ImGui::SFML::UpdateFontTexture();
	them = ImGui::GetStyle().Colors;
	tex_brush.loadFromFile("pen.png");
	tex_picker.loadFromFile("picker.png");
	tex_eraser.loadFromFile("eraser.png");
	tex_fill.loadFromFile("fill.png");
	tex_quad.loadFromFile("quad.png");
	tex_quadf.loadFromFile("quadf.png");
	tex_checker.loadFromFile("checker.png");
	tex_swap.loadFromFile("swap.png");
	tex_line.loadFromFile("line.png");
	tex_lchecker.loadFromFile("lchecker.png");
	tex_lgradient.loadFromFile("lgradient.png");
	gl.Enable((glEnum)gl.Texture2D);
	gl.Bind(0);
	gl.Depth(false);
	gl.Disable(glEnum::PointSmooth);
	gl.Enable(glEnum::Blend);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	gl.Ident();
	/*
	list<vex4ub> tex_colors;
	tex_colors = list<vex4ub>(256, vex4ub(Grey, 255));
	init_tex(grey_tex, tex_colors.data());
	uint j = 0, i = 0;
	for (auto& c : tex_colors) {
		if (j < 2 or j > 13 or i < 2 or i > 13)
			c = vex4ub(Red, 255);
		j++;
		if (j == 16) j = 0, i++;
	}
	init_tex(checkbox_tex, tex_colors.data());
	tex_colors.clear();
	*/
}
vex2f win_size, last_mouse = 0, cam_old = 0;
bool cam_move = false;
void cam() {
	win_size << Window.getSize();
	vex2f mouse = Mouse.Pos();
	mouse.y = mouse.y;
	mouse.x = win_size.x - mouse.x;
	if (!cam_move and Key.Pressed(Mouse.Right)) {
		cam_move = true;
		cam_old = mouse;
	};
	if (cam_move and !Key.Pressed(Mouse.Right))
		cam_move = false;
	if (Key.Pressed(Mouse.Right))
		last_mouse = mouse;
	const auto& spd = (last_mouse - cam_old) / 10.f;
	Cam.pos += spd;
	cam_old += spd;
	if (Event.type == sf::Event::MouseWheelScrolled) {
		if (Event.mouseWheelScroll.delta <= -1)
			Cam.zoom = std::max(.1f, Cam.zoom - .1f);
		else if (Event.mouseWheelScroll.delta >= 1)
			Cam.zoom = std::min(2.f, Cam.zoom + .1f);
		Event.type = sf::Event::Closed;
	}
	glScissor(0, 0, win_size.x, win_size.y);
	gl.Viewport(0, 0, win_size.x, win_size.y);
	glMatrixMode(GL_PROJECTION);
	gl.Ident();
	glLoadMatrixf(&Cam.matrix(win_size)[0][0]);
	glMatrixMode(GL_MODELVIEW);
	gl.Ident();
}
void gui();
sf::Clock imclk;
void play() {
	init();
	StyleDark();
	while (Window.isOpen()) {
		gl.Clear(glEnum::DepthBufferBit | glEnum::ColorBufferBit);
		gl.Clear.Color(BgColor.x, BgColor.y, BgColor.z);
		Window.clear();
		while (Window.pollEvent(Event)) {
			ImGui::SFML::ProcessEvent(Event);
			if (Event.type == sf::Event::Closed)
				Window.close();
		}
		cam();
		draw();
		ImGui::SFML::Update(Window, imclk.restart());
		Window.pushGLStates();
		gui();
		ImGui::SFML::Render(Window);
		Window.popGLStates();
		Window.display();
	}
}
uint size = 32;
int brush_size = 1;
f32 pixel_size = 5, fixel_size = 5;
vex4ub color = 255, color2 = vex4ub(0, 0, 0, 255);
bool color_t = true;
vex4f fcolor = 1.f, save_color = 0;
const vex4ub erase = 0;
list<vex4ub> tex = list<vex4ub>(size * size, vex4ub(0));
list<vex3i> pos = list<vex3i>(size * size, { 0,0,0 });
struct undo_t : list<vex4ub>::iterator {
	undo_t() = default;
	undo_t(const undo_t&) = default;
	undo_t(const list<vex4ub>::iterator& other) : color(*other), list<vex4ub>::iterator(other) { };
	undo_t(const vex4ub& c, const list<vex4ub>::iterator& other) : color(c), list<vex4ub>::iterator(other) { };
	vex4ub color;
};
list<undo_t> undo, redo;
void paint(int x, int y, const vex4ub& color, list<vex4ub>* tex = &::tex) {
	if (y < size and x < size and y >= 0 and x >= 0) {
		const auto& it = tex->begin() + (y + x * size);
		if (find(undo.begin(), undo.end(), it) == undo.end()) undo.push_back(undo_t(*it, it));
		*it = color;
	}
}
void paint_scr(f32 x, f32 y, const vex4ub& color, list<vex4ub>* tex = &::tex) {
	paint((x + Cam.pos.x) / fixel_size, (y + Cam.pos.y) / fixel_size, color, tex);
}
vex4ub get_color(int x, int y) {
	if (y < size and x < size and y >= 0 and x >= 0)
		return tex[y + x * size];
	return BgColor;
}
vex4ub get_color_scr(f32 x, f32 y) {
	return get_color((x + Cam.pos.x) / fixel_size, (y + Cam.pos.y) / fixel_size);
}
void paint_rect(f32 x, f32 y, int scale, const vex4ub& color) {
	const auto& half_s = scale / 2;
	const auto& fscale = scale - half_s;
	for (int i = -half_s; i < fscale; i++)
		for (int j = -half_s; j < fscale; j++)
			paint_scr(x + i * fixel_size, y + j * fixel_size, color);
}
void paint_fill(f32 x, f32 y, const vex4ub& color) {
	const auto& f_color = get_color_scr(x, y);
	std::for_each(tex.begin(), tex.end(), [&](auto& i) { if (f_color.x == i.x and f_color.y == i.y and f_color.z == i.z and f_color.w == i.w) i = color; });
}
list<vex4ub> ctex = tex;
enum class lines_t : byte { line_normal, line_checker, line_gradient };
using enum lines_t;
lines_t line_type = line_normal;
void paint_line(f32 x, f32 y, f32 x2, f32 y2, const vex4ub& color) {
	int begx =int((x + Cam.pos.x) / fixel_size) ;
	int endx =int((x2 + Cam.pos.x) / fixel_size);
	int begy =int((y + Cam.pos.y) / fixel_size);
	int endy = int((y2 + Cam.pos.y) / fixel_size);
	if (line_type == line_normal) {
		const f32 step = (abs(endx - begx)<abs(endy - begy)) ? (f32(endx-begx) /f32(endy-begy)) : (f32(endy - begy) / f32(endx - begx));
		if (abs(endx - begx) > abs(endy - begy)) {
			f32 fy = begy;
			if (begx < endx) {
				for (int i = begx; i <= endx; i++) {
					paint(i, (int)fy, color, &ctex);
					fy += step;
				}
			}
			else {
				for (int i = begx; i >= endx; i--) {
					paint(i, (int)fy, color, &ctex);
					fy -= step;
				}
			}
		}
		else {
			f32 fy = begx;
			if (begy < endy) {
				for (int i = begy; i <= endy; i++) {
					paint((int)fy, i, color, &ctex);
					fy += step;
				}
			}
			else {
				for (int i = begy; i >= endy; i--) {
					paint((int)fy, i, color, &ctex);
					fy -= step;
				}
			}
		}
	}
	else if (line_type == line_checker) {
		const f32 step = (abs(endx - begx) < abs(endy - begy)) ? (f32(endx - begx) / f32(endy - begy)) : (f32(endy - begy) / f32(endx - begx));
		bool cs = false;
		if (abs(endx - begx) > abs(endy - begy)) {
			f32 fy = begy;
			if (begx < endx) {
				for (int i = begx; i <= endx; i++) {
					paint(i, (int)fy, cs ? ::color : color2, &ctex);
					fy += step;
					cs = !cs;
				}
			}
			else {
				for (int i = begx; i >= endx; i--) {
					paint(i, (int)fy, cs ? ::color : color2, &ctex);
					fy -= step;
					cs = !cs;
				}
			}
		}
		else {
			f32 fy = begx;
			if (begy < endy) {
				for (int i = begy; i <= endy; i++) {
					paint((int)fy, i, cs ? ::color : color2, &ctex);
					fy += step;
					cs = !cs;
				}
			}
			else {
				for (int i = begy; i >= endy; i--) {
					paint((int)fy, i, cs ? ::color : color2, &ctex);
					fy -= step;
					cs = !cs;
				}
			}
		}
	}
	else if (line_type == line_gradient) {
		const f32 step = (abs(endx - begx) < abs(endy - begy)) ? (f32(endx - begx) / f32(endy - begy)) : (f32(endy - begy) / f32(endx - begx));
		vex4f clor = vex4f(::color) / 255.f;
		const vex4f clor2 = vex4f(color2) / 255.f;
		const vex4f fstep = (clor2 - clor) / std::max(fabs(endx - begx), fabs(endy - begy));
		if (abs(endx - begx) > abs(endy - begy)) {
			f32 fy = begy;
			if (begx < endx) {
				for (int i = begx; i <= endx; i++) {
					paint(i, (int)fy, vex4ub(clor * 255.f), &ctex);
					fy += step;
					clor += fstep;
				}
			}
			else {
				for (int i = begx; i >= endx; i--) {
					paint(i, (int)fy, vex4ub(clor * 255.f), &ctex);
					fy -= step;
					clor += fstep;
				}
			}
		}
		else {
			f32 fy = begx;
			if (begy < endy) {
				for (int i = begy; i <= endy; i++) {
					paint((int)fy, i, vex4ub(clor * 255.f), &ctex);
					fy += step;
					clor += fstep;
				}
			}
			else {
				for (int i = begy; i >= endy; i--) {
					paint((int)fy, i, vex4ub(clor * 255.f), &ctex);
					fy -= step;
					clor += fstep;
				}
			}
		}
	}
}
enum class quads_t : byte { quad_normal, quad_fill, quad_checker };
using enum quads_t;
quads_t quad_type = quad_normal;
void paint_quad(f32 x, f32 y, f32 x2, f32 y2, const vex4ub& color) {
	int begx = (x < x2) ? int((x + Cam.pos.x) / fixel_size) : int((x2 + Cam.pos.x) / fixel_size);
	int endx = (x < x2) ? int((x2 + Cam.pos.x) / fixel_size) : int((x + Cam.pos.x) / fixel_size);
	int begy = (y < y2) ? int((y + Cam.pos.y) / fixel_size) : int((y2 + Cam.pos.y) / fixel_size);
	int endy = (y < y2) ? int((y2 + Cam.pos.y) / fixel_size) : int((y + Cam.pos.y) / fixel_size);
	if (quad_type == quad_normal) {
		for (int i = begx; i <= endx; i++)
			paint(i, begy, color, &ctex), paint(i, endy, color, &ctex);
		for (int i = begy; i <= endy; i++)
			paint(begx, i, color, &ctex), paint(endx, i, color, &ctex);
	}
	else if (quad_type == quad_fill) {
		for (int i = begy; i <= endy; i++)
			for (int j = begx; j <= endx; j++)
				paint(j, i, color, &ctex);
	}
	else if (quad_type == quad_checker) {
		const vex4ub& fc = (color_t) ? ::color : color2;
		const vex4ub& sc = (color_t) ? color2 : ::color;
		bool s = false, l = false;
		{
			for (int i = begy; i <= endy; i++) {
				for (int j = begx; j <= endx; j++) {
					paint(j, i, s ? fc : sc, &ctex);
					s = !s;
				}
				s = l = !l;
			}
		}
	}
	/*
	if (x<x2) for (f32 i = x; i < x2; i+=fixel_size)
		paint_scr(i, y, color, &ctex), paint_scr(i, y2, color, &ctex);
	else if (x>x2) for (f32 i = x2; i < x; i+=fixel_size)
		paint_scr(i, y, color, &ctex), paint_scr(i, y2, color, &ctex);
	if (y<y2) for (f32 i = y; i < y2; i++)
		paint_scr(x, i, color, &ctex), paint_scr(x2, i, color, &ctex);
	else if (y>y2) for (f32 i = y2; i < y; i++)
		paint_scr(x, i, color, &ctex), paint_scr(x2, i, color, &ctex);
	*/
};
enum class status_t : byte { paint_t, picker_t, eraser_t, fill_t, quad_t, line_t };
using enum status_t;
status_t status = paint_t;
bool painting = false;
vex2f mouse_beg = 0;
void draw() {
	fixel_size = pixel_size * Cam.zoom;
	vex2f mouse;
	mouse << sf::Mouse::getPosition(Window);
	mouse.y = win_size.y - mouse.y;
	vex4ub& color = (color_t) ? ::color : color2;
	if (Window.hasFocus() and not painting and Key.Pressed(Mouse.Left) and (mouse.x > -Cam.pos.x and mouse.x - (f32)size * fixel_size < -Cam.pos.x) and (mouse.y > -Cam.pos.y and mouse.y - (f32)size * fixel_size < -Cam.pos.y)) {
		painting = true;
		if (status == picker_t) {
			color = get_color_scr(mouse.x + fixel_size / 2, mouse.y + fixel_size / 2);
			status = paint_t;
		}
		else {
			if (status == quad_t or status == line_t) mouse_beg = mouse;
			undo.clear();
			redo.clear();
		}
	}
	if (painting) {
		if (not Key.Pressed(Mouse.Left)) {
			painting = false;
			if (status == quad_t or status == line_t) tex = ctex;
		}
		else {
			if (status == paint_t) {
				if (brush_size == 1)
					paint_scr(mouse.x + fixel_size / 2, mouse.y + fixel_size / 2, color);
				else if (brush_size > 1)
					paint_rect(mouse.x + fixel_size / 2, mouse.y + fixel_size / 2, brush_size, color);
			}
			else if (status == eraser_t) {
				if (brush_size == 1)
					paint_scr(mouse.x + fixel_size / 2, mouse.y + fixel_size / 2, erase);
				else if (brush_size > 1)
					paint_rect(mouse.x + fixel_size / 2, mouse.y + fixel_size / 2, brush_size, erase);
			}
			else if (status == fill_t) {
				paint_fill(mouse.x + fixel_size / 2, mouse.y + fixel_size / 2, color);
				painting = false;
			}
			else if (status == quad_t) {
				ctex = tex;
				paint_quad(mouse_beg.x + fixel_size / 2, mouse_beg.y + fixel_size / 2, mouse.x + fixel_size / 2, mouse.y + fixel_size / 2, color);
			}
			else if (status == line_t) {
				ctex = tex;
				paint_line(mouse_beg.x + fixel_size / 2, mouse_beg.y + fixel_size / 2, mouse.x + fixel_size / 2, mouse.y + fixel_size / 2, color);
			}
		}
	}
	gl.Color(34, 30, 30);
	gl.Begin(gl.Quad);
	gl.Vertex.Rect((size * pixel_size) / 2 - pixel_size / 2, (size * pixel_size) / 2 - pixel_size / 2, (size * pixel_size) / 2 + pixel_size / 2, (size * pixel_size) / 2 + pixel_size / 2);
	gl.End();
	gl.PointSize(fixel_size);
	gl.Enable.ClientState(glEnum::VertexArray);
	gl.VertexPointer(3, gl.Int, sizeof(vex3i), pos.data());
	gl.Enable.ClientState(glEnum::ColorArray);
	glColorPointer(4, GL_UNSIGNED_BYTE, sizeof(vex4ub), ((status == quad_t or status == line_t) and painting) ? ctex.data() : tex.data());
	gl.DrawArrays(gl.Point, pos.size());
	gl.Disable.ClientState(glEnum::VertexArray);
	gl.Disable.ClientState(glEnum::ColorArray);
}
const f32 b_size = 25, no_bg = 0.02, on_bg = 0.05;
template <bool is_last> bool button_gui(auto s, auto& tex, const str& tool_tip) {
	if (status == s) them[ImGuiCol_Button].w = on_bg;
	bool is_p = false;
	if (is_p = im::ImageButton(tex, { b_size, b_size })) status = s;
	if (im::IsItemHovered()) {
		im::BeginTooltip();
		im::Text(tool_tip.c_str());
		im::EndTooltip();
	}
	if (status == s) them[ImGuiCol_Button].w = no_bg;
	if constexpr (is_last == false) im::SameLine();
	return is_p;
}
const ImVec4 Redf		 = ImVec4(248/255.f, 29 /255.f, 67 /255.f, 1.f);
const ImVec4 DarkGreenf  = ImVec4(0  /255.f, 98 /255.f, 67 /255.f, 1.f);
const ImVec4 Bluef		 = ImVec4(0  /255.f, 179/255.f, 233/255.f, 1.f);
const ImVec4 Pinkf		 = ImVec4(255/255.f, 221/255.f, 227/255.f, 1.f);
const ImVec4 DarkBluef	 = ImVec4(91 /255.f, 73 /255.f, 226/255.f, 1.f);
const ImVec4 Greyf		 = ImVec4(58 /255.f, 57 /255.f, 73 /255.f, 1.f);
const ImVec4 Purplef	 = ImVec4(143/255.f, 10 /255.f, 165/255.f, 1.f);
const ImVec4 Orangef	 = ImVec4(255/255.f, 91 /255.f, 23 /255.f, 1.f);
const ImVec4 Yellowf	 = ImVec4(232/255.f, 255/255.f, 53 /255.f, 1.f);
const ImVec4 Limef		 = ImVec4(140/255.f, 229/255.f, 15 /255.f, 1.f);
void color_gui(vex4f& col) {
	const f32 cs = 20;
	if (im::ColorButton("red", Redf, 0, { cs,cs })) col << Redf;
	im::SameLine(); if (im::ColorButton("green", DarkGreenf, 0, { cs,cs })) col << DarkGreenf;
	im::SameLine(); if (im::ColorButton("blue", Bluef, 0, { cs,cs })) col << Bluef;
	im::SameLine(); if (im::ColorButton("pink", Pinkf, 0, { cs,cs })) col << Pinkf;
	im::SameLine(); if (im::ColorButton("dark blue", DarkBluef, 0, { cs,cs })) col << DarkBluef;
	im::SameLine(); if (im::ColorButton("grey", Greyf, 0, { cs,cs })) col << Greyf;
	im::SameLine(); if (im::ColorButton("purple", Purplef, 0, { cs,cs })) col << Purplef;
	im::SameLine(); if (im::ColorButton("orange", Orangef, 0, { cs,cs })) col << Orangef;
	im::SameLine(); if (im::ColorButton("yellow", Yellowf, 0, { cs,cs })) col << Yellowf;
	im::SameLine(); if (im::ColorButton("lime", Limef, 0, { cs,cs })) col << Limef;
}
void gui() {
	im::Begin("Debug");
	const auto sb = them[ImGuiCol_Button];
	them[ImGuiCol_ButtonActive].w = them[ImGuiCol_ButtonHovered].w = on_bg;
	them[ImGuiCol_Button] = ImVec4(Grey.x, Grey.y, Grey.z, no_bg);
	{
		button_gui<0>(paint_t, tex_brush, "pen");
		button_gui<0>(picker_t, tex_picker, "color picker");
		button_gui<0>(eraser_t, tex_eraser, "eraser");
		const bool q_t = (status == quad_t);
		if (button_gui<0>(quad_t,
			(quad_type == quad_normal) ? tex_quad : (quad_type == quad_fill) ? tex_quadf : tex_checker,
			(quad_type == quad_normal) ? "square tool" : (quad_type == quad_fill) ? "square tool [filled]" : "checker tool")) {
			if (q_t) {
				if (quad_type == quad_checker)
					quad_type = quad_normal;
				else
					quad_type = quads_t(byte(quad_type) + 1);
			}
		}
		const bool l_t = (status == line_t);
		if (button_gui<0>(line_t,
			(line_type == line_normal) ? tex_line : (line_type == line_checker) ? tex_lchecker : tex_lgradient,
			(line_type == line_normal) ? "line tool" : (line_type == line_checker) ? "line tool [checker]" : "line tool [gradient]")) {
			if (l_t) {
				if (line_type == line_gradient)
					line_type = line_normal;
				else
					line_type = lines_t(byte(line_type) + 1);
			}
		}
		button_gui<1>(fill_t, tex_fill, "fill tool");
	}
	them[ImGuiCol_Button] = sb;
	{
		if (im::Button("Undo") and not undo.empty()) {
			for (auto& u : undo) {
				redo.push_back(undo_t(*u, u));
				*u = u.color;
			}
			undo.clear();
		}
		im::SameLine();
		if (im::Button("Redo") and not redo.empty()) {
			for (auto& u : redo) {
				undo.push_back(undo_t(*u, u));
				*u = u.color;
			}
			redo.clear();
		}
	}
	im::SliderInt("Brush Size", &brush_size, 1, 10);
	const f32 button_s = 35;
	if (color_t) {
		fcolor = v4f(color) / 255.f;
		if (im::ColorButton("color1", { fcolor.x, fcolor.y, fcolor.z, fcolor.w }, ImGuiColorEditFlags_NoTooltip, { button_s,button_s }))
			im::OpenPopup("color1 edit");
		if (im::BeginPopup("color1 edit")) {
			im::ColorPicker4("Color", *fcolor);
			color_gui(fcolor);
			color = fcolor * 255;
			im::EndPopup();
		}
		im::SetCursorPos({ im::GetCursorPosX() + button_s + 5, im::GetCursorPosY() - 30 });
		if (im::ImageButton(tex_swap, { 15, 15 }))
			color_t = !color_t;
		im::SetCursorPos({ im::GetCursorPosX() + button_s * 2, im::GetCursorPosY() - 35 });
		fcolor = v4f(color2) / 255.f;
		if (im::ColorButton("color2", { fcolor.x, fcolor.y, fcolor.z, fcolor.w }, ImGuiColorEditFlags_NoTooltip, { button_s,button_s }))
			im::OpenPopup("color2 edit");
		if (im::BeginPopup("color2 edit")) {
			im::ColorPicker4("Color", *fcolor);
			color_gui(fcolor);
			color2 = fcolor * 255;
			im::EndPopup();
		}
	}
	else {
		fcolor = v4f(color2) / 255.f;
		if (im::ColorButton("color2", { fcolor.x, fcolor.y, fcolor.z, fcolor.w }, ImGuiColorEditFlags_NoTooltip, { button_s,button_s }))
			im::OpenPopup("color2 edit");
		if (im::BeginPopup("color2 edit")) {
			im::ColorPicker4("Color", *fcolor);
			color_gui(fcolor);
			color2 = fcolor * 255;
			im::EndPopup();
		}
		im::SetCursorPos({ im::GetCursorPosX() + button_s + 5, im::GetCursorPosY() - 30 });
		if (im::ImageButton(tex_swap, { 15, 15 }))
			color_t = !color_t;
		im::SetCursorPos({ im::GetCursorPosX() + button_s * 2, im::GetCursorPosY() - 35 });
		fcolor = v4f(color) / 255.f;
		if (im::ColorButton("color1", { fcolor.x, fcolor.y, fcolor.z, fcolor.w }, ImGuiColorEditFlags_NoTooltip, { button_s,button_s }))
			im::OpenPopup("color1 edit");
		if (im::BeginPopup("color1 edit")) {
			im::ColorPicker4("Color", *fcolor);
			color_gui(fcolor);
			color = fcolor * 255;
			im::EndPopup();
		}
	}
	im::End();
}
auto main() -> int {
	for (uint i = 0; i < size; i++)
		for (uint j = 0; j < size; j++)
			pos[i * size + j] = vex2i { i * pixel_size,j * pixel_size };
	play();
}
