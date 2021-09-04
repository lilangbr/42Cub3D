NAME = cub3D

CC = clang

FLAGS = -Wall -Wextra -Werror

HEADERS = -I ./includes

LIBFT_DIR = ./libs/libft

LIBMLX_DIR = ./libs/minilibx-linux

ADD_LIBS = -lm -lbsd -lXext -lX11 -L $(LIBFT_DIR) -lft -L $(LIBMLX_DIR) -lmlx

SRCS = ./src/allocate.c \
		./src/args_verify.c \
		./src/close_cub.c \
		./src/cub3D.c \
		./src/errors.c \
		./src/errors_input.c \
		./src/errors_sys.c \
		./src/file_check_full_opt.c \
		./src/file_get_floorc.c \
		./src/file_get_textures.c \
		./src/file_parse.c \
		./src/file_read.c \
		./src/frees.c \
		./src/game_casting_rays.c \
		./src/game_cast_one_h_hit.c \
		./src/game_cast_one_hit_dist.c \
		./src/game_cast_one_ray.c \
		./src/game_cast_one_v_hit.c \
		./src/game_draw_elements.c \
		./src/game_draw_minimap.c \
		./src/game_draw_miniplayer.c \
		./src/game_draw_walls.c \
		./src/game_fill_texture.c \
		./src/game_images.c \
		./src/game_key.c \
		./src/game_push_img.c \
		./src/game_render.c \
		./src/game_render_minimap.c \
		./src/game_render_reset.c \
		./src/game_setup.c \
		./src/game_textures.c \
		./src/game_utils.c \
		./src/get_next_line.c \
		./src/get_next_line_utils.c \
		./src/init_structs_part_one.c \
		./src/init_structs_part_two.c \
		./src/map_check.c \
		./src/map_fill_spaces.c \
		./src/map_normalize.c \
		./src/map_read.c \
		./src/map_validate.c \
		./src/map_validate_closed.c \
		./src/map_validate_limits.c \
		./src/map_validate_player.c \
		./src/play.c \
		./src/str_cutfirsts.c \
		./src/str_handled.c \
		./src/str_tools.c \
		./src/str_trim_begin.c

OBJS = $(SRCS:.c=.o)

RM = /bin/rm -f

all:	$(NAME)

$(NAME):	$(OBJS) libft minilibx-linux
	$(CC) $(FLAGS) $(HEADERS) $(OBJS) $(ADD_LIBS) -o $@

%.o:	%.c    
	$(CC) $(FLAGS) $(HEADERS) -c $< -o $@

libft:
	make -C $(LIBFT_DIR)

minilibx-linux:
	make -C $(LIBMLX_DIR)
	
clean:
	make clean -C $(LIBFT_DIR)
	make clean -C $(LIBMLX_DIR)
	$(RM) ./src/*.o 
	

fclean:	clean
	make fclean -C $(LIBFT_DIR)
	$(RM) $(NAME)
	
re: fclean all

.PONY: all clean fclean re
