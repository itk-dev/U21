<?php

class mmsParser extends FeedsParser {

  public function parse(FeedsImportBatch $batch, FeedsSource $source) {
 
    // Parser data
    $items = array();
    $xml = new SimpleXMLElement($batch->getRaw());
    
    // Run through news items
    foreach ($xml->message as $message) {
      $item = array();
      $item['mid'] = (string)$message['mid'];
      $item['msgid'] = (string)$message['msgid'];
      $item['timestamp'] = (string)$message['timestamp'];
      $item['text'] = (string)$message->text;
      $item['image'] = (string)$message->image;
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
      'image' => array(
        'name' => t('Image link'),
        'description' => t('Link to the image in the files folder.'),
      ),
    );
  }
}