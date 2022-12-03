#include <iostream>

class Log
{
public:
	enum Level
	{
		LevelError = 0,
		LevelWarning,
		LevelInfo
	};

	explicit Log(const Level level)
	{
		m_level = level;
	}

	Level m_level = LevelInfo;

	void set_level(const Level level)
	{
		m_level = level;
	}

	void info(const char* message) const
	{
		if (m_level >= LevelInfo)
			std::cout << "[INFO]: " << message << std::endl;
	}


	void warn(const char* message) const
	{
		if (m_level >= LevelWarning)
			std::cout << "[WARNING]: " << message << std::endl;
	}


	void error(const char* message) const
	{
		if (m_level >= LevelError)
			std::cout << "[ERROR]: " << message << std::endl;
	}
};


void fun_with_loggers()
{
	Log logger(Log::LevelInfo);

	logger.warn("This is bad");
	logger.info("This is not interesting");
	logger.error("This is critical");

	logger.set_level(Log::LevelWarning);
	logger.warn("This is bad");
	logger.info("This is not interesting");
	logger.error("This is critical");
}

