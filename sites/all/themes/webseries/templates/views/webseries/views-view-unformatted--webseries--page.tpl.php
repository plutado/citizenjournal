<?php

/**
 * @file
 * Default simple view template to display a list of rows.
 *
 * @ingroup views_templates
 */
?>

<script src="http://ajax.googleapis.com/ajax/libs/jquery/1.9.1/jquery.min.js"></script>
<script>window.jQuery || document.write('<script src="sites/all/themes/webseries/js/libs/jquery-1.10.1.min.js"><\/script>')</script>

<div class="episode-data" style="display:none;">

  <?php if (!empty($title)): ?>
    <h3><?php print $title; ?></h3>
  <?php endif; ?>
  <?php foreach ($rows as $id => $row): ?>
    <?php print $row; ?>
  <?php endforeach; ?>

</div>


<script>

/*Video height and width*/
var yt_height = 393;
var yt_width = 700;

$(document).ready(function () {
  var yt_html = "";

  var yt_subheading = "<h3>" + yt_subheading + "</h3>";

  for (var num=0, len=yt_videos.length; num<len; ++num){
    yt_html = yt_html + "<div class='four columns column-"+ num +"'><a class='skip' gumby-easing='easeInOutQuad' gumby-offset='-20' gumby-goto='#yt_container' gumby-duration='2000' onclick='change_embeded(\"" + yt_videos[num] + "\")'><div class='play'><img src='sites/all/themes/webseries/img/play.png' /></div><div class='video-thumbnail'><img src='http://img.youtube.com/vi/"+yt_videos[num]+"/hqdefault.jpg' width='480' height='360'/></div></a><h4 class='video-title video-title-"+num+"'><span class='title'>"+yt_titles[num]+"</span><div style='display:none;' class='currently-playing'> (currently selected) </div></h4></div>";

    $('#yt_container').html(''
                      + '<div id="yt_embededvideo" class="video youtube">'
                      + '<iframe "'
                      + yt_width
                      + '" height="'
                      + yt_height
                      + '" src="//www.youtube.com/embed/'
                      + episode_1
                      +'" frameborder="0" allowfullscreen></iframe></div><h2 class="current-episode">'
                      + yt_titles[0]
                      + '</h2>'
                      + '<h3 class="subheading">'
                      + subheading_1
                      + '</h3>'
                      + '<p class="btn primary more-details">'
                      + '<a href="#" id="show" class="toggle" gumby-trigger="#drawer1">'
                      + 'show more'
                      + '</a>'
                      + '</p>'
                      + '<div class="drawer" id="drawer1"><div class="close-button">'
                      + '<a href="#" id="close-video-details" class="toggle" gumby-trigger="#drawer1">'
                      + '<i class="icon-cancel-circled"></i></a></div>'
                      + '<section class="tabs">'
                      + '<ul class="tab-nav">'
                      + '<li class="active"><a href="#">Show Notes</a></li>'
                      + '<li><a href="#">Transcript</a></li>'
                      + '<li><a href="#">Share & Comment</a></li>'
                      + '</ul>'
                      + '<div class="tab-content active">'
                      + '<div class="notes">'
                      + yt_show_notes[0]
                      + '</div>'
                      + '</div>'
                      + '<div class="tab-content">'
                      + '<div class="transcript">'
                      + yt_transcript[0]
                      + '</div>'
                      + '</div>'
                      + '<div class="tab-content">'
                      + '<p>test</p>'
                      + '</div>'
                      + '</section>'
                      +'</div>');


    $('.grid-wrapper').html('<div id="video-grid" class="row">'+yt_html+'</div>');

  }

});


function change_embeded(video_id){

    $('#yt_embededvideo').html('<iframe "'+ yt_width +'" height="'+ yt_height +'" src="//www.youtube.com/embed/'+ video_id +'?autoplay=1" frameborder="0" allowfullscreen></iframe>');

    if (video_id == episode_1) {
      $('h2.current-episode').html($(".title_0").text());
      $('h3.subheading').html($(".subheading_0").text());
      $('.notes').html($(".body-0").html());
      $('.transcript').html(transcript_1);
      $('.video-title .currently-playing').hide();
      $('.video-title-0 .currently-playing').show();
    }

    else if (video_id == episode_2) {
      $('h2.current-episode').html($(".title_1").text());
      $('h3.subheading').html($(".subheading_1").text());
      $('.notes').html($(".body-1").html());
      $('.transcript').html(transcript_2);
      $('.video-title .currently-playing').hide();
      $('.video-title-1 .currently-playing').show();
    }

    else if (video_id == episode_3) {
      $('h2.current-episode').html($(".title_2").text());
      $('h3.subheading').html($(".subheading_2").text());
      $('.notes').html($(".body-2").html());
      $('.transcript').html(transcript_3);
      $('.video-title .currently-playing').hide();
      $('.video-title-2 .currently-playing').show();
    }

    else if (video_id == episode_4) {
      $('h2.current-episode').html($(".title_3").text());
      $('h3.subheading').html($(".subheading_3").text());
      $('.notes').html($(".body-3").html());
      $('.transcript').html(transcript_4);
      $('.video-title .currently-playing').hide();
      $('.video-title-3 .currently-playing').show();
    }

    else if (video_id == episode_5) {
      $('h2.current-episode').html($(".title_4").text());
      $('h3.subheading').html($(".subheading_4").text());
      $('.notes').html($(".body-4").html());
      $('.transcript').html(transcript_5);
      $('.video-title .currently-playing').hide();
      $('.video-title-4 .currently-playing').show();
    }

    else if (video_id == episode_6) {
      $('h2.current-episode').html($(".title_5").text());
      $('h3.subheading').html($(".subheading_5").text());
      $('.notes').html($(".body-5").html());
      $('.transcript').html(transcript_6);
      $('.video-title .currently-playing').hide();
      $('.video-title-5 .currently-playing').show();
    }

    else if (video_id == episode_7) {
      $('h2.current-episode').html($(".title_6").text());
      $('h3.subheading').html($(".subheading_6").text());
      $('.notes').html($(".body-6").html());
      $('.transcript').html(transcript_7);
      $('.video-title .currently-playing').hide();
      $('.video-title-6 .currently-playing').show();
    }

    else if (video_id == episode_8) {
      $('h2.current-episode').html($(".title_7").text());
      $('h3.subheading').html($(".subheading_7").text());
      $('.notes').html($(".body-7").html());
      $('.transcript').html(transcript_8);
      $('.video-title .currently-playing').hide();
      $('.video-title-7 .currently-playing').show();
    }

    else if (video_id == episode_9) {
      $('h2.current-episode').html($(".title_8").text());
      $('h3.subheading').html($(".subheading_8").text());
      $('.notes').html($(".body-8").html());
      $('.transcript').html(transcript_9);
      $('.video-title .currently-playing').hide();
      $('.video-title-8 .currently-playing').show();
    }

}

var episode_1 = $(".video_id_0").text();
var episode_2 = $(".video_id_1").text();
var episode_3 = $(".video_id_2").text();
var episode_4 = $(".video_id_3").text();
var episode_5 = $(".video_id_4").text();
var episode_6 = $(".video_id_5").text();
var episode_7 = $(".video_id_6").text();
var episode_8 = $(".video_id_7").text();
var episode_9 = $(".video_id_8").text();

var yt_videos = [episode_1, episode_2, episode_3, episode_4, episode_5, episode_6, episode_7, episode_8, episode_9];


var title_1 = $(".title_0").text();
var title_2 = $(".title_1").text();
var title_3 = $(".title_2").text();
var title_4 = $(".title_3").text();
var title_5 = $(".title_4").text();
var title_6 = $(".title_5").text();
var title_7 = $(".title_6").text();
var title_8 = $(".title_7").text();
var title_9 = $(".title_8").text();

var yt_titles = [title_1, title_2, title_3, title_4, title_5, title_6, title_7, title_8, title_9];


var subheading_1 = $(".subheading_0").text();
var subheading_2 = $(".subheading_1").text();
var subheading_3 = $(".subheading_2").text();
var subheading_4 = $(".subheading_3").text();
var subheading_5 = $(".subheading_4").text();
var subheading_6 = $(".subheading_5").text();
var subheading_7 = $(".subheading_6").text();
var subheading_8 = $(".subheading_7").text();
var subheading_9 = $(".subheading_8").text();

var yt_subheading = [subheading_1, subheading_2, subheading_3, subheading_4, subheading_5, subheading_6, subheading_7, subheading_8, subheading_9];


var show_notes_1 = $(".body-0").html();
var show_notes_2 = $(".body-1").html();
var show_notes_3 = $(".body-2").html();
var show_notes_4 = $(".body-3").html();
var show_notes_5 = $(".body-4").html();
var show_notes_6 = $(".body-5").html();
var show_notes_7 = $(".body-6").html();
var show_notes_8 = $(".body-7").html();
var show_notes_9 = $(".body-8").html();

var yt_show_notes = [show_notes_1, show_notes_2, show_notes_3, show_notes_4, show_notes_5, show_notes_6, show_notes_7, show_notes_8, show_notes_9];


var transcript_1 = $(".transcript-0").html();
var transcript_2 = $(".transcript-1").html();
var transcript_3 = $(".transcript-2").html();
var transcript_4 = $(".transcript-3").html();
var transcript_5 = $(".transcript-4").html();
var transcript_6 = $(".transcript-5").html();
var transcript_7 = $(".transcript-6").html();
var transcript_8 = $(".transcript-7").html();
var transcript_9 = $(".transcript-8").html();

var yt_transcript = [transcript_1, transcript_2, transcript_3, transcript_4, transcript_5, transcript_6, transcript_7, transcript_8, transcript_9]

</script>

<div class="feature-video-container" data-target="yt_container">
  <div class="row">
    <div class="twelve columns centered" id="yt_container"></div>
  </div>
</div>
<div class="grid-wrapper"></div>
