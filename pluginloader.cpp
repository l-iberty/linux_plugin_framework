#include "pluginloader.h"


PluginLoader::PluginLoader() {
    if (getDllFilePaths((char *) PLUGIN_DIR, m_LibPaths)) { // get *.so paths
        // get *.so module handle
        for (int i = 0; i < m_LibPaths.size(); i++) {
            void *hMod = dlopen(m_LibPaths.at(i).c_str(), RTLD_LAZY);
            if (hMod != NULL)
                m_hModList.push_back(hMod);
        }
    }
}

PluginLoader::~PluginLoader() {
    for (int i = 0; i < m_hModList.size(); i++)
        dlclose(m_hModList.at(i));
}

bool PluginLoader::getDllFilePaths(char *path, vector<string> &paths) {
    DIR *dir;
    struct dirent *ent;
    char childpath[MAX_PATH];

    dir = opendir(path);
    if (dir == NULL)
        return false;


    while ((ent = readdir(dir)) != NULL) {
        if (ent->d_type & DT_DIR)
            continue;

        bzero(childpath, MAX_PATH);
        strncpy(childpath, path, MAX_PATH);
        strcat(childpath, ent->d_name);

        paths.push_back(childpath);
    }
    return true;
}

vector<string> &PluginLoader::getPluginNames() {
    char szName[MAX_PATH];

    for (int i = 0; i < m_hModList.size(); i++) {
        void *hLibMod = m_hModList.at(i);
        PLUGIN_PROC_NAME getPluginName = (PLUGIN_PROC_NAME)
                dlsym(hLibMod, "getPluginName");
        if (getPluginName != NULL) {
            getPluginName(szName);
            m_PluginNames.push_back(szName);
        }
    }
    return m_PluginNames;
}

vector<void *> &PluginLoader::getDllModList() {
    return m_hModList;
}

