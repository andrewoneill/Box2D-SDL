#include <LButton.h>


LButton::LButton( int x, int y, SDL_Renderer* gRenderer, std::string s1, std::string s2){
	m_x = x;
	m_y = y;
	m_isClicked = false;
	m_clicked.loadFromFile(s2, gRenderer);
	m_unclicked.loadFromFile(s1, gRenderer);
	m_currentSprite = m_unclicked;
	m_width = m_currentSprite.getWidth();
	m_height = m_currentSprite.getHeight();
}

void LButton::HandleEvent( SDL_Event *e ){
	if( e->type == SDL_MOUSEMOTION || 
		e->type == SDL_MOUSEBUTTONDOWN || 
		e->type == SDL_MOUSEBUTTONUP ){//If mouse event happened
			int x, y;
			SDL_GetMouseState( &x, &y ); //Get mouse position
			bool inside = true;
			if( x < m_x )//Mouse is left of the button
				inside = false;
			else if( x > m_x + m_width )//Mouse is right of the button
				inside = false;
			else if( y < m_y )//Mouse above the button
				inside = false;
			else if( y > m_y + m_height)//Mouse below the button
				inside = false;
			if( !inside )//Mouse is outside button
				m_currentSprite = m_unclicked;
			else{//Mouse is inside button
				switch( e->type ){
					// case SDL_MOUSEMOTION:
					// mCurrentSprite = BUTTON_SPRITE_MOUSE_OVER_MOTION;
					// break;
				case SDL_MOUSEBUTTONDOWN:
					m_currentSprite = m_clicked;
					m_isClicked = true;
					break;
				case SDL_MOUSEBUTTONUP:
					m_currentSprite = m_unclicked;
					SDL_Delay(100);
					break;
				}
			}
	}
}
bool LButton::IsClicked(){
	return m_isClicked;
}
void LButton::Draw(SDL_Renderer *gRenderer){
	m_currentSprite.render(m_x, m_y, NULL, NULL, 0, SDL_FLIP_NONE, gRenderer );
	SDL_RenderPresent( gRenderer );
}
LButton::~LButton(){

}
