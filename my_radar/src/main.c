/*
** EPITECH PROJECT, 2022
** B-MUL-100-LIL-1-1-myradar-remi.fernandez
** File description:
** TODO: add description
*/
#include "../includes/my.h"

sfRenderWindow *create_window(unsigned int width,unsigned int height,int bits)
{
    sfRenderWindow *window;
    sfVideoMode video_mode;
    video_mode.width = width;
    video_mode.height = height;
    video_mode.bitsPerPixel = bits;
    window = sfRenderWindow_create(video_mode,"My Radar",sfResize |
                                                            sfClose,NULL);
    sfRenderWindow_setFramerateLimit(window, 60);
    return (window);
}

void close_window(MAIN_T *GLOB, sfClock* clock3)
{
    do {
        if (GLOB->param.event.type == sfEvtClosed)
            sfRenderWindow_close(WINDOW);
        if (EVENT.type == sfEvtKeyPressed) {
            if (EVENT.key.code == sfKeyL && GLOB->l == 1) {
                sfTime elapsed = sfClock_getElapsedTime(clock3);
                check_l(GLOB, clock3, elapsed);
            } if (EVENT.key.code == sfKeyL && GLOB->l == 0) {
                sfTime elapsed = sfClock_getElapsedTime(clock3);
                check_l2(GLOB, clock3, elapsed);
            } if (EVENT.key.code == sfKeyS && GLOB->s == 1) {
                sfTime elapsed = sfClock_getElapsedTime(clock3);
                check_s(GLOB, clock3, elapsed);
            } if (EVENT.key.code == sfKeyS && GLOB->s == 0) {
                sfTime elapsed = sfClock_getElapsedTime(clock3);
                check_s2(GLOB, clock3, elapsed);
            }
        }
    } while (sfRenderWindow_pollEvent(WINDOW, &EVENT));
}

int screen_loop(MAIN_T *GLOB)
{
    sfClock* clock = sfClock_create();
    sfClock* clock2 = sfClock_create();
    sfClock* clock3 = sfClock_create();
    sfTime elapsed; float seconds;
    while (sfRenderWindow_isOpen(WINDOW)) {
        elapsed = sfClock_getElapsedTime(clock2);
        seconds = sfTime_asSeconds(elapsed);
        sfRenderWindow_clear(WINDOW, sfWhite);
        sfRenderWindow_drawSprite(WINDOW, MAP.sprite, NULL);
        my_draw_tower(GLOB);
        my_draw_plane(GLOB, seconds);
        move_plane(GLOB, clock, seconds);
        print_timer(GLOB, seconds);
        sfRenderWindow_display(WINDOW);
        if (check_finish(GLOB) == 1)
            sfRenderWindow_close(WINDOW);
        close_window(GLOB, clock3);
    }
    sfRenderWindow_destroy(WINDOW);
    return 0;
}

int read_file (int argc, char ** argv, MAIN_T *GLOB)
{
    char *script;
    struct stat buf;
    stat(argv[1], &buf);
    if (errno) {
        write(2, "Script file don't exist or is wrong\n", 37);
        return 84;
    }
    script = malloc(buf.st_size + sizeof(char));
    int fd = open(argv[1],O_RDONLY);
    read(fd,script,buf.st_size + sizeof(char));
    if (check_script(script) == 84) {
        write(2, "Wrong script file\n", 19);
        return 84;
    }
    if (check_assets(GLOB) == 84)
        return 84;
    put_in_chained(GLOB, script);
    return 0;
}

int main (int argc, char ** argv)
{
    MAIN_T GLOB;
    if (argv[1][0] == '-' && argv[1][1] == 'h') {
        usage_h();
        return 0;
    } if (argc != 2) {
        write(2, "Wrong number of parameters\nRetry with -h\n", 41);
        return 84;
    } intialise_list(&GLOB);
    if (read_file(argc, argv, &GLOB) == 84) {
        return 84;
    } GLOB.param.window = create_window(1920, 1080, 64);
    if (init_background(&GLOB) == 84)
        return 84;
    if (init_text(&GLOB) == 84)
        return 84;
    GLOB.l = 0; GLOB.s = 0;
    screen_loop(&GLOB);
    return 0;
}
