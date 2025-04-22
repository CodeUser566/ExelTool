from conan import ConanFile
from conan.tools.cmake import cmake_layout # type: ignore


class ExampleRecipe(ConanFile):
    settings = "os", "compiler", "build_type", "arch"
    generators = "CMakeDeps", "CMakeToolchain"

    def requirements(self):
        self.requires("libxlsxwriter/1.1.9")
        self.requires("libqrencode/4.1.1")

    def layout(self):
        cmake_layout(self)