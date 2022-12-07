#include <iostream>

class Log
{
public:
	enum Level
	{
		kError = 0,
		kWarning,
		kInfo
	};

	explicit Log(const Level level)
	{
		m_level = level;
	}

	Level m_level = kInfo;

	void SetLevel(const Level level)
	{
		m_level = level;
	}

	void Info(const char* message) const
	{
		if (m_level >= kInfo)
			std::cout << "[INFO]: " << message << std::endl;
	}


	void Warn(const char* message) const
	{
		if (m_level >= kWarning)
			std::cout << "[WARNING]: " << message << std::endl;
	}


	void Error(const char* message) const
	{
		if (m_level >= kError)
			std::cout << "[ERROR]: " << message << std::endl;
	}
};


void FunWithLoggers()
{
	Log logger(Log::kInfo);

	logger.Warn("This is bad");
	logger.Info("This is not interesting");
	logger.kError("This is critical");

	logger.SetLevel(Log::kWarning);
	logger.Warn("This is bad");
	logger.Info("This is not interesting");
	logger.kError("This is critical");
}

