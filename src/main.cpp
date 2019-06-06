#include <stdio.h>
#include <Windows.h>

#define SET_LOCALE

int main(int argc, char **argv) {
#ifdef SET_LOCALE
	SetConsoleCP(1251);                
    SetConsoleOutputCP(1251);
#endif
	//HWND hWnd = GetConsoleWindow();
    //ShowWindow(hWnd, SW_HIDE);
	bool doLog = true;
	char scriptFile[256];
	char logFile[256];
	if (argc > 1) {
		sprintf(scriptFile, "%s", argv[1]);
	}
	else {
		// default script file
		sprintf(scriptFile, "script.bat");
	}
	if (argc == 3) {
		sprintf(logFile, "%s", argv[2]);
		doLog = (strcmp(logFile, "-nolog") != 0);
	}
	else {
		// default log file
		sprintf(logFile, "log.txt");
	}
	FILE *pFile = fopen(scriptFile, "r");
	if (pFile != nullptr) {
		/*printf("file \"%s\" is open. ", scriptFile);
		if (doLog) {
			printf(" log is \"%s\".\n", logFile);
		}
		else {
			printf(" log is here.\n");
		}*/
		while (!feof(pFile)) {
			char line[1024];
			fscanf(pFile, "%[^\n]s", line);
			//printf("%s\n", line);
			if (doLog) {
				char *commandLine = new char[strlen(line) + strlen(logFile) + 10]; // "line >> logFile"
				sprintf(commandLine, "%s >> %s", line, logFile);
				system(commandLine);
				delete commandLine;
			}
			else {
				system(line);
			}
		}
		fclose(pFile);
	}
	else {
		//printf("file not found!\n");
	}
	return 0;
}