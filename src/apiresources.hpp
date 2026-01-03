#ifndef APIRESOURCES_HPP
    #define APIRESOURCES_HPP
namespace redmine::api_resources {
	static const QString ISSUE = QStringLiteral("issues/%0.json"); // arg[0] == id
	static const QString ISSUES = QStringLiteral("issues.json");
	static const QString PROJECT = QStringLiteral("projects/%0.json"); // arg[0] == id
	static const QString PROJECTS = QStringLiteral("projects.json");
	static const QString TIME_ENTRY = QStringLiteral("time_entries/%0.json"); // arg[0] == id
	static const QString TIME_ENTRIES = QStringLiteral("time_entries.json");
}

#endif // !APIRESOURCES_HPP
