typedef struct t_commands
{
	char *path_line;
	char **paths;
	char **cmd_1;
	char **cmd_2;
	char **envp;

}t_commands;

typedef struct t_files
{
	int infile;
	int outfile;
}t_files;
