#pragma once

class Integer {
	int *m_pInt;
public:
	//constructor
	Integer();
	//Parameterized constructor
	Integer(int val);
	//destructor
	~Integer();
	//Copy constrctor
	Integer(const Integer &obj);
	//Copy Operator

	//Move constructor
	Integer(Integer &&obj);
	//Why use it for move constructors?
	//Standard containers(e.g., std::vector) will only use move operations if they are marked noexcept. Otherwise, they fall back to copy operations, which can be less efficient.
	//nteger(Integer&& Obj) noexcept;
	
	//Move Operator

	//Getter
	int getInteger() const;
	//Setter
	void setInteger(int val);
};