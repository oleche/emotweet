<?php

include 'lib/EpiCurl.php';
include 'lib/EpiOAuth.php';
include 'lib/EpiTwitter.php';
include 'cfg/secret.php';

# Create a Twitter object
$twitterObj = new EpiTwitter($consumer_key, $consumer_secret, $access_token, $access_secret);

# Get tweets
$status = $twitterObj->get('/statuses/user_timeline.json');
$response = $status->response;
$mood = "T";

# Show actual texts of the tweets
foreach ($response as $tweet) {
  echo $latest = $tweet["text"] . "\n";
  $pos = strpos ($latest, "happy");
  if ($pos !== false) {
    $mood = "H";
  }
  $pos = strpos ($latest, "sad");
  if ($pos !== false) {
    $mood = "S";
  }

  $pos = strpos ($latest, "angry");
  if ($pos !== false) {
    $mood = "A";
  }

  $pos = strpos ($latest, "meh");
  if ($pos !== false) {
    $mood = "P";
  }
  
  $pos = strpos ($latest, "love");
  if ($pos !== false) {
    $mood = "L";
  }

  curl_download("https://agent.electricimp.com/vu2OgSTPqmlA?data=".$mood);
  break;
}

function curl_download($Url){
 
    // is cURL installed yet?
    if (!function_exists('curl_init')){
        die('Sorry cURL is not installed!');
    }
 
    // OK cool - then let's create a new cURL resource handle
    $ch = curl_init();
 
    // Now set some options (most are optional)
 
    // Set URL to download
    curl_setopt($ch, CURLOPT_URL, $Url);
 
    // Set a referer
    curl_setopt($ch, CURLOPT_REFERER, "http://www.example.org/yay.htm");
 
    // User agent
    curl_setopt($ch, CURLOPT_USERAGENT, "MozillaXYZ/1.0");
 
    // Include header in result? (0 = yes, 1 = no)
    curl_setopt($ch, CURLOPT_HEADER, 0);
 
    // Should cURL return or print out the data? (true = return, false = print)
    curl_setopt($ch, CURLOPT_RETURNTRANSFER, true);
 
    // Timeout in seconds
    curl_setopt($ch, CURLOPT_TIMEOUT, 10);
 
    // Download the given URL, and return output
    $output = curl_exec($ch);
 
    // Close the cURL resource, and free system resources
    curl_close($ch);
 
    return $output;
}
?>