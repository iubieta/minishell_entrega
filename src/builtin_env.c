
#include "minishell.h"

void	ft_env(char **env)
{
	if (!env)
	{
		printf("ft_env: env array doesnt exist\n");
		return ;
	}
	while (*env)
	{
		if (ft_strchr(*env, '='))
			printf("%s\n", *env);
		else
			printf("env: string with invalid format on env array\n");
		env++;
	}
}

// TEST
int	main()
{
	char	**env;

	printf("\n--Test 1--\n");
	ft_arprint(NULL);
	ft_env(NULL);

	printf("\n--Test 2--\n");
	env = ft_calloc(10, sizeof(char *));
	env[0] = ft_strdup("Var1=Value1");
	env[1] = NULL;
	ft_arprint(env);
	ft_env(env);
	ft_arfree(env);

	printf("\n--Test 3--\n");
	env = ft_calloc(10, sizeof(char *));
	ft_arprint(env);
	ft_env(env);
	ft_arfree(env);

	printf("\n--Test 4--\n");
	env = ft_calloc(10, sizeof(char *));
	env[0] = ft_strdup("Var1=Value1");
	env[1] = ft_strdup("Var2Value2");
	env[2] = NULL;
	ft_arprint(env);
	ft_env(env);
	ft_arfree(env);

	printf("\n--Test 5--\n");
	env = ft_calloc(10, sizeof(char *));
	env[0] = ft_strdup("Var1=Value1");
	env[1] = ft_strdup("Var2=Value2");
	env[2] = ft_strdup("Var3=Value3");
	env[3] = ft_strdup("Var4=Value4");
	env[4] = NULL;
	ft_arprint(env);
	ft_env(env);
	ft_arfree(env);
	
	printf("\n--Test 6--\n");
	env = ft_calloc(10, sizeof(char *));
	env[0] = ft_strdup("Var1=Value1");
	env[1] = ft_strdup("Var2Value2");
	env[2] = ft_strdup("Var3Value3");
	env[3] = ft_strdup("Var4=Value4");
	env[4] = NULL;
	ft_arprint(env);
	ft_env(env);
	ft_arfree(env);

}
