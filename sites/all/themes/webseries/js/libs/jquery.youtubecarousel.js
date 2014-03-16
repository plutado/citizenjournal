/*!
 * Built on top of the jQuery library
 *   http://jquery.com
 *
 * YouTubeCarousel - YouTube Carousel and Player
 *   http://www.michaelsouellette.com/youtubecarousel/
 *
 * Copyright (c) 2011 Michael S. Ouellette (http://www.michaelsouellette.com)
 * Dual licensed under the MIT (http://www.opensource.org/licenses/mit-license.php)
 * and GPL (http://www.opensource.org/licenses/gpl-license.php) licenses.
 *
 *----------------------------------------------------------------------------
 *
 * jCarousel - Riding carousels with jQuery
 *   http://sorgalla.com/jcarousel/
 *
 */


/*List of YouTube videos - you need just the video ID for this (ex:)*/
var yt_videos = ['qRGVD-gFuRc','txqiwrbYGrs','dMH0bHeiRNg','Z3ZAGBL6UBA','60og9gwKh1o','2K-TICdG1R8','CdD8s0jFJYo','Q5im0Ssyyus'];

/*Video height and width*/
var yt_height = 393;
var yt_width = 700;

/*-----DO NOT EDIT BELOW THIS-----*/
jQuery(document).ready(function () {
	var yt_html = "";
	
	for (var num=0, len=yt_videos.length; num<len; ++num){
		yt_html = yt_html + "<div class='three columns'><a onclick='change_embeded(\"" + yt_videos[num] + "\")'><img src='http://img.youtube.com/vi/"+yt_videos[num]+"/1.jpg' class='video-thumbnail' style='height:300px;' /></a></div>";
	}
	
	jQuery('#yt_container').html('<div id="yt_embededvideo" class="video youtube"><iframe "'+ yt_width +'" height="'+ yt_height +'" src="//www.youtube.com/embed/'+ yt_videos[0] +'" frameborder="0" allowfullscreen></iframe></div><div id="video-grid" class="row">'+yt_html+'</div>');
	
});


function change_embeded(video_id){
	jQuery('#yt_embededvideo').html('<iframe "'+ yt_width +'" height="'+ yt_height +'" src="//www.youtube.com/embed/'+ video_id +'" frameborder="0" allowfullscreen></iframe>');
}
