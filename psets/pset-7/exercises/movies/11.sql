SELECT m.title FROM movies m JOIN stars s ON m.id = s.movie_id JOIN people p ON s.person_id = p.id AND p.name = 'Chadwick Boseman' JOIN ratings r ON m.id = r.movie_id ORDER BY r.rating DESC LIMIT 5;
