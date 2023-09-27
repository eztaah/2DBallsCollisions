# Create AppImage

1. Download the appimagetool executable here [AppimageTool](https://appimage.github.io/appimagetool/)

<br>

2. Add the appimagetool executable to your $PATH and make it executable :
    ```bash
    sudo mv ./appimagetool-x86_64.AppImage /usr/local/bin/appimagetool
    sudo chmod a+x /usr/local/bin/appimagetool
    ```

<br>

3. Create your AppImage file :
    ```bash
    appimagetool ~/Desktop/MyApp.AppDir ~/Desktop
    ```
