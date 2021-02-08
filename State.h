#ifndef State_hpp
#define State_hpp


class State
{
private:
	static State* currentState;

protected:
	State* table[5];

public:
	static State* getState();
	static void setState(State* state);

	State();
	virtual void update();
	virtual void render();
	void InitTable(State* tab[5]);

};

#endif

