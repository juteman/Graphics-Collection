cmake_minimum_required(VERSION 3.12)
project(DX12Common)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

file(GLOB SOURCE "*.cpp" "*.h")

add_library(DX12Common ${SOURCE})

target_link_libraries(DX12Common 
PUBLIC
    d3d12.lib dxgi.lib dxguid.lib uuid.lib
    kernel32.lib user32.lib
    comdlg32.lib advapi32.lib shell32.lib
    ole32.lib oleaut32.lib
    runtimeobject.lib
    DirectXTK12
)