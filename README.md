Абдуллин Саид БПИ 218

ДЗ 6

Файлы server.c и client.с соответственно отвечают за серверную и клиетскую части.
Клиент создает разделяемую память с ключом 1234 и записывает в нее случайную последовательность цифр длиной BUF_SIZE(32).
Сервер пытается подключиться к этой разделяемой памяти, вывести ее содержимое, и если получилось, то удалить ее с помощью shmctl.
