The Folder Structure

first_base_wii/
├── .github/
│   └── workflows/
│       └── build.yml      <-- GitHub Actions automated build script
├── source/
│   └── main.cpp           <-- Your main C or C++ code file
├── include/               <-- (Optional) Header files (.h / .hpp)
├── data/                  <-- (Optional) Assets like images, audio, or fonts
├── Makefile               <-- Instructions telling devkitPro how to compile
├── icon.png               <-- (Optional) 128x48 PNG icon for Homebrew Channel
├── meta.xml               <-- (Optional) App info (title, author, description)
└── README.md              <-- Project description
