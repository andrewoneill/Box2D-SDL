#ifndef LBUTTON_H
#define LBUTTON_H
#include <SDL_dev\SDL2-2.0.3\include\SDL.h>
#include <LTexture.h>

class LButton{
private:
	int m_x, m_y;
	int m_width, m_height;
	bool m_isClicked;
	LTexture m_currentSprite, m_clicked, m_unclicked;
public:
	LButton(int, int, SDL_Renderer*, std::string, std::string);
	void HandleEvent(SDL_Event*);
	void Draw(SDL_Renderer*);
	bool IsClicked();
	~LButton(void);
};

#endif