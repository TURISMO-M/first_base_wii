#include <stdio.h>
#include <stdlib.h>
#include <gccore.h>
#include <wiiuse/wpad.h>

static void *xfb = NULL;
static GXRModeObj *rmode = NULL;

int main(int argc, char **argv) {
    // Initialize video and Wiimote subsystem
    VIDEO_Init();
    WPAD_Init();
    
    // Obtain TV mode and setup framebuffers
    rmode = VIDEO_GetPreferredMode(NULL);
    xfb = MEM_K0_TO_K1(SYS_AllocateFramebuffer(rmode));
    CONSOLE_Init(xfb, 20, 20, rmode->fbWidth, rmode->xfbHeight, rmode->fbWidth * VI_DISPLAY_PIX_SZ);
    
    VIDEO_Configure(rmode);
    VIDEO_SetNextFramebuffer(xfb);
    VIDEO_SetBlack(FALSE);
    VIDEO_Flush();
    VIDEO_WaitVSync();
    
    if (rmode->viTVMode & VI_NON_INTERLACE) VIDEO_WaitVSync();

    // Print text to the screen
    printf("\x1b[20;0HHello, Wii World!");

    // Main game loop
    while(1) {
        WPAD_ScanPads();
        u32 pressed = WPAD_ButtonsDown(0);
        
        // Press HOME on the Wiimote to exit back to Homebrew Channel
        if (pressed & WPAD_BUTTON_HOME) exit(0);
        
        VIDEO_WaitVSync();
    }

    return 0;
}

