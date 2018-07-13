import logging
from scraper_project.books.app import books_list

logger = logging.getLogger('scraping.menu')
USER_CHOICE = '''Enter one of the following

-'b' to look at 5-star books
-'c' to look at the cheapest books
-'n' to just get the next available book on the catalogue
-'q' to exit

Enter your choice : '''


def print_best_books():
    logger.info('Finding best books by rating...')
    best_books = sorted(books_list, key=lambda x: (x.rating * -1, x.price))[:10]
    for book in best_books:
        print(book)


def print_cheapest_books():
    logger.info('Finding best books by price...')
    cheapest_books = sorted(books_list, key=lambda x: x.price)[:10]
    for book in cheapest_books:
        print(book)


book_generator = (x for x in books_list if len(books_list) != 0)


def get_next_book():
    logger.info('Getting next book from generator of all books...')
    try:
        first = next(book_generator)
    except StopIteration:
        print('No book left')
        return None
    print(first)


user_choice = {
    'b': print_best_books,
    'c': print_cheapest_books,
    'n': get_next_book
}


def menu():
    user_input = input(USER_CHOICE)
    while user_input != 'q':
        if user_input in ('b', 'c', 'n'):
            user_choice[user_input]()
        else:
            print('Enter valid character')
        user_input = input(USER_CHOICE)
    logger.debug('Terminating program...')


menu()
