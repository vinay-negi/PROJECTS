import re
import logging
from bs4 import BeautifulSoup

from scraper_project.books.locators.all_books_page import Allbookspagelocators
from scraper_project.books.parsers.book_parser import Bookparser

logger = logging.getLogger('scraping.all_books_page')


class AllBooksPage:
    def __init__(self, page_content):
        logger.debug('Parsing page content with BeautifulSoup HTML parser.')
        self.soup = BeautifulSoup(page_content, 'html.parser')

    @property
    def books(self):
        logger.debug(f'Finding all books in the page using `{Allbookspagelocators.Books}`.')
        return [Bookparser(e) for e in self.soup.select(Allbookspagelocators.Books)]

    @property
    def page_count(self):
        logger.debug(f'Finding all number of catalogue pages available.')
        content = self.soup.select_one(Allbookspagelocators.PAGER).string
        logger.info(f'Found number of catalogue pages available : `{content}`.')
        pattern = 'Page [0-9]+ of ([0-9]+)'
        matcher = re.search(pattern, content)
        pages = int(matcher.group(1))
        logger.debug(f'Extracted number of pages as integer : `{pages}`.')
        return pages
