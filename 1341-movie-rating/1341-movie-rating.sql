(
    SELECT u.name AS results
    FROM MovieRating mr, Users u
    WHERE mr.user_id = u.user_id
    GROUP BY mr.user_id
    ORDER BY COUNT(1) DESC, u.name
    LIMIT 1
)
UNION ALL
(
    SELECT m.title AS results
    FROM MovieRating mr, Movies m 
    WHERE mr.movie_id = m.movie_id AND mr.created_at LIKE '2020-02%'
    GROUP BY mr.movie_id
    ORDER BY AVG(rating) DESC, m.title
    LIMIT 1
)


# Here's a breakdown of the SQL code with explanations:

# 1. First Subquery:

# Purpose: Finds the user with the most movie ratings.
# Breakdown:
# SELECT u.name AS results ...: Selects the name of the user, aliasing it as results.
# FROM MovieRating mr, Users u ...: Joins MovieRating and Users tables to match ratings with user information.
# WHERE mr.user_id = u.user_id ...: Ensures correct matching based on user IDs.
# GROUP BY mr.user_id ...: Groups ratings by user, allowing aggregations per user.
# ORDER BY COUNT(1) DESC, u.name ...: Orders users by the number of ratings they have (descending), then alphabetically by name.
# LIMIT 1: Selects only the first user (the one with the most ratings).
# 2. Second Subquery:

# Purpose: Finds the highest-rated movie among those rated in February 2020.
# Breakdown:
# SELECT m.title AS results ...: Selects the title of the movie, aliasing it as results.
# FROM MovieRating mr, Movies m ...: Joins MovieRating and Movies tables to match ratings with movie information.
# WHERE mr.movie_id = m.movie_id AND mr.created_at LIKE '2020-02%' ...: Filters ratings for movies rated in February 2020 based on the created_at timestamp.
# GROUP BY mr.movie_id ...: Groups ratings by movie, allowing aggregations per movie.
# ORDER BY AVG(rating) DESC, m.title ...: Orders movies by their average rating (descending), then alphabetically by title.
# LIMIT 1: Selects only the first movie (the one with the highest average rating).
# 3. UNION ALL:

# Combines the results of the two subqueries, preserving duplicates. This means both the user with the most ratings and the highest-rated movie will be included in the final output, even if they happen to have the same name.
# Overall, the query:

# Identifies the two separate pieces of information (most-ratings user and highest-rated movie).
# Presents them as a single column named results.
# The user's name and the movie's title will be displayed in the same format due to the common alias.