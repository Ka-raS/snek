#pragma once

#include <filesystem>
#include "raylib.h"

namespace configs
{
    constexpr int fpsTarget = 60;
    constexpr int windowInitWidth = 900;
    constexpr int windowInitHeight = 600;

    constexpr const char *windowTitle = "snek";
    constexpr ConfigFlags windowInitConfig = ConfigFlags::FLAG_WINDOW_RESIZABLE;
    constexpr Color backgroundColor{0x00, 0x00, 0x00, 0xff}; // BLACK

    inline const std::filesystem::path rootDirectory = "..";
    inline const std::filesystem::path windowIconPath = rootDirectory / "resources" / "icon.png";

} // namespace configs