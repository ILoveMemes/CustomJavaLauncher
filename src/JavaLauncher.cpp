#include <stdio.h>
#include <Windows.h>

#define SET_LOCALE

int main(int argc, char **argv) {
#ifdef SET_LOCALE
	SetConsoleCP(1251);                
    SetConsoleOutputCP(1251);
#endif
	bool doLog = true;
	char jarFile[256];
	char logFile[256];
	if (argc > 1) {
		sprintf(jarFile, "%s", argv[1]);
	}
	else {
		// default script file
		sprintf(jarFile, "main.jar");
	}
	if (argc == 3) {
		sprintf(logFile, "%s", argv[2]);
		doLog = (strcmp(logFile, "-nolog") != 0);
	}
	else {
		// default log file
		sprintf(logFile, "log.txt");
	}
	char *commandLine = new char[strlen(jarFile) + strlen(logFile) + 15]; // "java -jar jarFile >> logFile"
	if (doLog) {
		sprintf(commandLine, "java -jar %s >> %s", jarFile, logFile);
	}
	else {
		sprintf(commandLine, "java -jar %s", jarFile);
	}
	printf("%s", commandLine);
	system(commandLine);
	delete commandLine;
	return 0;
}