<?php

class uefaParser extends FeedsParser {

  public function parse(FeedsImportBatch $batch, FeedsSource $source) {
    $data_raw = $batch->getRaw();
  

    // Parser data
    $items = array();
    $xml = new SimpleXMLElement($data_raw);

    // Run through news items
    foreach ($xml->news as $news) {
      $item = array();
      $item['newsId'] = $news['newsId'];
      $item['newsTitle'] = $news->newsTitle;
      $item['newsDate'] = $news->newsDate;
      $item['newsComment'] = $news->newsComment;
      $item['newsLink'] = $news->newsLink;
      $items[] = $item;
    }

    $batch->setTitle('News list');
    $batch->setItems($items);
  }

  public function getMappingSources() {
    return array(
      'newsId' => array(
        'name' => t('News ID'),
        'description' => t('The unique news id.'),
      ),
      'newsTitle' => array(
        'name' => t('Title'),
        'description' => t('News title.'),
      ),
      'newsDate' => array(
        'name' => t('Date'),
        'description' => t('The news item post date.'),
      ),
      'newsComment' => array(
        'name' => t('News comment'),
        'description' => t('News teaser or comment'),
      ),
      'newsLink' => array(
        'name' => t('Link'),
        'description' => t('Link to the news at www.uefa.com'),
      ),
    );
  }
}