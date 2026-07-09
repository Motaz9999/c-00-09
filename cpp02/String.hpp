#ifndef STRING_HPP
# define STRING_HPP
# include <iostream>
# include <string>
class String
{
  private:
	char *_data;
	int _length;

  public:
	String();
	String(std::string const &content);
	String(String const &other); // copy constructor
	String& operator=(String const &other);
	~String();

	// other fun
	std::string getContent() const;
	int getLength() const;
	void setContent(std::string const &s);
	void print(std::string const &label) const;
};
#endif