#ifndef CALCULATOR_DISPLAY_HPP
#define CALCULATOR_DISPLAY_HPP

#include <SFML/Graphics.hpp>
#include <string>

namespace dv {
class Display : public sf::Drawable, public sf::Transformable {
 public:
  Display() {
    shape_.setSize(sf::Vector2f(600.f, 60.f));
    shape_.setFillColor(sf::Color(46, 46, 56));

    font_.loadFromFile("Raleway.ttf");
    text_.setFont(font_);
    text_.setFillColor(sf::Color::White);
    text_.setCharacterSize(24);
    
    arrow_.setFont(font_);
    arrow_.setFillColor(sf::Color::White);
    arrow_.setCharacterSize(40);
    arrow_.setString("<");
    arrow_.setPosition(sf::Vector2f(565.f, 2.f));
  
    reset();
  }

  void addValue(std::string value);

  void reset() {
    strText_ = "0";
    text_.setString(strText_);
    text_.setPosition(sf::Vector2f(500.f, 15.f));
  }

  void draw(sf::RenderTarget& target, sf::RenderStates states) const {
    states.transform *= getTransform();
    target.draw(shape_, states);
    target.draw(text_, states);
    target.draw(arrow_, states);
  }

 private:
  sf::RectangleShape shape_;
  std::string strText_;
  sf::Text text_;
  sf::Text arrow_;
  sf::Font font_;
};

}  // namespace dv

#endif  // CALCULATOR_DISPLAY_HPP