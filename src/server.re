let app = Express.App.make();

let renderHTML = (_next, _req, res) => {
  let content = ReactDOMServerRe.renderToString(<App />);
  Express.Response.sendString(Template.make(~content, ~title="ReasonReact SSR Starter", ()), res);
};

Express.Static.defaultOptions()
|> Express.Static.make("dist/")
|> Express.Static.asMiddleware
|> Express.App.useOnPath(app, ~path="/dist");

Express.Static.defaultOptions()
|> Express.Static.make("static/")
|> Express.Static.asMiddleware
|> Express.App.useOnPath(app, ~path="/static");

renderHTML |> Express.Middleware.from |> Express.App.useOnPath(~path="/", app);

let port = 3000;

let onListen = e =>
  switch e {
  | exception (Js.Exn.Error(e)) =>
    Js.log(e);
    Node.Process.exit(1);
  | _ => Js.log("Listening at http://localhost:" ++ string_of_int(port))
  };

Express.App.listen(app, ~onListen, ~port, ());
