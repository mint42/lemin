int		realloc_pids_array(size_t **array, size_t *size, size_t new_size_min)
{
	size_t	*new_array;
	size_t	old_size;
	size_t	i;

	old_size = *size;
	while (*size < new_size_min)
		*size = *size * 2;
	new_array = ft_memalloc(sizeof(size_t *) * size);
	if (!new_array)
		return (print_error(E_ALLOC_ERROR));
	i = 0;
	while (i < old_size)
	{
		new_array[i] = (*array)[i];
		++i;
	}
	ft_memdel(array);
	*array = new_array;
	return (0);
}

int		add_pid(size_t **array, size_t *size, size_t index, size_t bit)
{
	if (size < index)
		if (realloc_pids_array(array, size, index) == ERROR)
			return (ERROR);
	(*array)[index] = (*array)[index] & bit;
	return (0);
}

