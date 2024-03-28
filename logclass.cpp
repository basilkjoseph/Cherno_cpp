#include<iostream>
using namespace std;


class Log
{
public:
	enum Level
	{
		LevelError=0,LevelWarning,LevelInfo
	};
private:
	Level m_Loglevel = LevelInfo;
public:
	void setlevel(Level level)
	{
		m_Loglevel = level;
	}
	void warn(const char* message)
	{
		if (m_Loglevel >= LevelWarning)
			cout << "[WARNING]" << message << endl;
	}
	void info(const char* message)
	{
		if (m_Loglevel >= LevelInfo)
			cout << "[INFO]" << message << endl;
	}
	void error(const char* message)
	{
		if (m_Loglevel >= LevelError)
			cout << "[ERROR]" << message << endl;
	}
};

int main()
{

	Log log;
	log.setlevel(log.LevelInfo);
	log.warn("Hello!");
	log.info("Hello!");
	log.error("Hello!");

	cin.get();
}