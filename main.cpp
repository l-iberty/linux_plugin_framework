#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include "pluginloader.h"

using namespace std;

int main() {
    int op;
    FILE *fp;
    PLUGIN_PROC_RUN run;

    PluginLoader pluginLoader = PluginLoader();
    vector<string> &pluginNames = pluginLoader.getPluginNames();
    vector<void *> &dllMods = pluginLoader.getDllModList();

    // list functions provided by plugins
    for (int i = 0; i < pluginNames.size(); i++)
        printf("[%d] %s\n", i, pluginNames.at(i).c_str());

    fp = fopen(__FILE__, "r");

    while (1) {
        printf("\nEnter operation code: ");
        scanf("%d", &op);

        if (op < 0 || op >= pluginNames.size()) {
            printf("exit\n");
            break;
        }

        run = (PLUGIN_PROC_RUN) dlsym(dllMods.at(op), "run");
        if (run != NULL)
            run(fp); // execute the function of plugin
    }

    fclose(fp);
    return EXIT_SUCCESS;
}
