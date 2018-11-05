let make = (~content, ~title, ()) => {j|
  <!DOCTYPE html>
    <html>
      <head>
        <title>$title</title>
        <link rel="stylesheet" type="text/css" href="/static/styles.css" />
      </head>
      <body>
        <div id="root">$content</div>
        <script src="/dist/bundle.js"></script>
      </body>
    </html>
|j};
