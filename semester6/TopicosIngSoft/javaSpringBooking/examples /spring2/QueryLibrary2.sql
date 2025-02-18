/*library2 querys*/

-- Mostrar todos los autores
SELECT * FROM author;

-- Mostrar un autor por ID
SELECT * FROM author WHERE id = 'ID_DEL_AUTOR';

-- Contar cuántos autores hay
SELECT COUNT(*) FROM author;

-- Buscar autores por nombre (ejemplo: nombres que contienen "John")
SELECT * FROM author WHERE name LIKE '%John%';

-------------------------------------------------------------

-- Mostrar todos los libros
SELECT * FROM book;

-- Mostrar un libro por ISBN
SELECT * FROM book WHERE isbn = 123456789;

-- Mostrar libros de un autor específico
SELECT * FROM book WHERE author_id = 'ID_DEL_AUTOR';

-- Mostrar libros de una editorial específica
SELECT * FROM book WHERE publisher_id = 'ID_DEL_EDITORIAL';

-- Buscar libros por título
SELECT * FROM book WHERE tittle LIKE '%Harry Potter%';

-- Contar cuántos libros hay en total
SELECT COUNT(*) FROM book;

-- Mostrar libros ordenados por fecha de entrada (más recientes primero)
SELECT * FROM book ORDER BY entryDate DESC;

----------------------------------------------------------------

-- Mostrar todas las imágenes
SELECT * FROM image;

-- Mostrar una imagen específica por ID
SELECT * FROM image WHERE id = 'ID_DE_LA_IMAGEN';

-- Mostrar todas las imágenes de un tipo específico (ejemplo: PNG)
SELECT * FROM image WHERE mime = 'image/png';

-- Contar cuántas imágenes hay
SELECT COUNT(*) FROM image;

---------------------------------------------------------------

-- Mostrar todas las editoriales
SELECT * FROM publisher;

-- Mostrar una editorial por ID
SELECT * FROM publisher WHERE id = 'ID_DE_LA_EDITORIAL';

-- Buscar editoriales por nombre
SELECT * FROM publisher WHERE name LIKE '%Penguin%';

-- Contar cuántas editoriales hay
SELECT COUNT(*) FROM publisher;

--------------------------------------------------------------


-- Mostrar todos los usuarios
SELECT * FROM user;
role
-- Mostrar un usuario por ID
SELECT * FROM user WHERE id = 'ID_DEL_USUARIO';

-- Buscar usuarios por nombre
SELECT * FROM user WHERE name LIKE '%Carlos%';

-- Buscar un usuario por email
SELECT * FROM user WHERE email = 'correo@example.com';

-- Contar cuántos usuarios hay en total
SELECT COUNT(*) FROM user;

-- Mostrar usuarios con un rol específico (ejemplo: ADMIN)
SELECT * FROM user WHERE role = 'ADMIN';

-- Mostrar usuarios con imagen asociada
SELECT * FROM user WHERE image_id IS NOT NULL;

-- importante cambiar tipo de usuario a ADMIN 
UPDATE user SET role = 'ADMIN' WHERE id = '7fd6af46-abee-4382-b122-f71a37d313fc';


