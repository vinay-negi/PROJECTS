import re
import logging
from scraper_project.books.locators.book_locators import Book_locators

logger = logging.getLogger('scraping.bok_parser')


class Bookparser:
    Rating = {
        'One': 1,
        'Two': 2,
        'Three': 3,
        'Four': 4,
        'Five': 5
    }

    def __init__(self, parent):
        logger.debug(f'New book parser created from : `{parent}`.')
        self.parent = parent

    def __repr__(self):
        return f'<Book {self.name}, £{self.price} ({self.rating} stars)>'

    @property
    def name(self):
        logger.debug('Finding book name...')
        locator = Book_locators.Name_locator
        item_link = self.parent.select_one(locator)
        item_name = item_link.attrs['title']
        logger.debug(f'Found book name : `{item_name}`.')
        return item_name

    @property
    def link(self):
        logger.debug('Finding book link...')
        locator = Book_locators.Link_locator
        item_link = self.parent.select_one(locator).attrs['href']
        logger.debug(f'Found book link : `{item_link}`.')
        return item_link

    @property
    def price(self):
        logger.debug('Finding book price...')
        locator = Book_locators.Price_locator
        item_price = self.parent.select_one(locator).string
        pattern = '£([0-9]+\.[0-9]+)'
        matcher = re.search(pattern, item_price)
        price_val = float(matcher.group(1))
        logger.debug(f'Found book price : `{price_val}`.')
        return float(matcher.group(1))

    @property
    def rating(self):
        logger.debug('Finding book rating...')
        locator = Book_locators.Rating_locator
        star_rating_tag = self.parent.select_one(locator)
        classes = star_rating_tag.attrs['class']
        rating_classes = [r for r in classes if r != 'star-rating']
        rating_int = Bookparser.Rating.get(rating_classes[0])
        logger.debug(f'Found book price : `{rating_int}`.')
        return rating_int
