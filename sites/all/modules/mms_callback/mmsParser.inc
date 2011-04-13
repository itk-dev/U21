<?php

class mmsParser extends FeedsParser {

  public function parse(FeedsImportBatch $batch, FeedsSource $source) {
 
    // Parser data
    $items = array();
    $xml = new SimpleXMLElement($batch->getRaw());
    
    // Run through news items
    foreach ($xml->message as $message) {
      $item = array();
      $item['title'] = 'Photo_'.(string)$message['mid'];
      $item['mid'] = (string)$message['mid'];
      $item['msgid'] = (string)$message['msgid'];
      $item['timestamp'] = (string)$message['timestamp'];
      $item['text'] = (string)$message->text;
      $item['taxonomy'] = (string)$message->taxonomy;
      $item['uploaded'] = 'Ja';
      
      // Convert XML image to array
      $images = array();
      foreach ($message->image as $url) {
        $images[] = (string)$url;
      }
      $item['images'] = $images;

      // Add feed item
      $items[] = $item;
    }

    $batch->setTitle('Message list');
    $batch->setItems($items);
  }

  public function getMappingSources() {
    return array(
      'mid' => array(
        'name' => t('Drupal message ID'),
        'description' => t('The unique drupal message id.'),
      ),
      'title' => array(
        'name' => t('Photo title'),
        'description' => t('Unique title for the photo.'),
      ),
      'msgid' => array(
        'name' => t('MMS message ID'),
        'description' => t('MMS message id received with the message.'),
      ),
      'timestamp' => array(
        'name' => t('Timestamp'),
        'description' => t('The time of message repection.'),
      ),
      'text' => array(
        'name' => t('MMS text'),
        'description' => t('Text sendt with the MMS.'),
      ),
      'taxonomy' => array(
        'name' => t('Taxonomy keyword'),
        'description' => t('Second word sendt in the MMS.'),
      ),
      'images' => array(
        'name' => t('Image(s) link'),
        'description' => t('Link to the image in the files folder.'),
      ),
      'uploaded' => array(
        'name' => t('User uploaded'),
        'description' => t('User uploaded photo (1).'),
      ),
    );
  }
}