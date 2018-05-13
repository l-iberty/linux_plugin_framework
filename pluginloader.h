#ifndef PLUGINLOADER_H
#define PLUGINLOADER_H

#include <iostream>
#include <string>
#include <vector>
#include <dlfcn.h>
#include <unistd.h>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

#define PLUGIN_DIR "./plugins/"
#define MAX_PATH 256

typedef void (*PLUGIN_PROC_NAME)(char *);

typedef void (*PLUGIN_PROC_RUN)(FILE *);

class PluginLoader {
public:
    PluginLoader();

    ~PluginLoader();

    vector<string> &getPluginNames();

    vector<void *> &getDllModList();

private:
    bool getDllFilePaths(char *path, vector<string> &paths);

private:
    vector<string> m_LibPaths; // DLL 文件的绝对路径
    vector<string> m_PluginNames; // 插件名
    vector<void *> m_hModList; // 插件句柄
};

#endif // PLUGINLOADER_H
