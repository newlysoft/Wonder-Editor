open DragEventUtils;

type state = {style: ReactDOMRe.Style.t};

module Method = {
  let onDoubleClick = AssetTreeUtils.onSelect;

  let onClick = FileBox.Method.onSelect;
};

let component = ReasonReact.reducerComponent("FolderBox");

let reducer = ((onDrop, _, _), action, state) =>
  switch (action) {
  | DragStart =>
    ReasonReact.Update({
      ...state,
      style: ReactUtils.addStyleProp("opacity", "0.2", state.style),
    })

  | DragEnter =>
    ReasonReact.Update({
      ...state,
      style:
        ReactUtils.addStyleProp("border", "2px dashed blue", state.style),
    })

  | DragLeave =>
    ReasonReact.Update({
      ...state,
      style: ReactUtils.addStyleProp("border", "1px solid red", state.style),
    })

  | DragEnd =>
    ReasonReact.Update({
      ...state,
      style:
        ReactUtils.addStyleProp("opacity", "1", state.style)
        |> ReactUtils.addStyleProp("border", "1px solid red"),
    })

  | DragDrop(targetId, removedId) =>
    let (flag, _) =
      StateEditorService.getState()
      |> CurrentDragSourceEditorService.getCurrentDragSource;

    ReasonReactUtils.sideEffects(() => onDrop((targetId, removedId, flag)));

  | Nothing => ReasonReact.NoUpdate
  };

let render =
    (
      store,
      dispatchFunc,
      attributeTuple,
      funcTuple,
      {state, send}: ReasonReact.self('a, 'b, 'c),
    ) => {
  let (dragImg, imgSrc, folderId, name, _isSelected, flag) = attributeTuple;
  let (_onDrop, handleFlag, handleRelationError) = funcTuple;
  let id = "folder-" ++ string_of_int(folderId);
  <article className="file-item" id style=state.style>
    <div
      className="item-ground"
      draggable=true
      onDragStart=(
        _e =>
          send(DragEventUtils.handleDragStart(folderId, flag, dragImg, _e))
      )
      onDragEnd=(_e => send(DragEventUtils.handleDrageEnd(_e)))
      onDragEnter=(
        _e =>
          send(
            DragEventUtils.handleDragEnter(
              folderId,
              handleFlag,
              handleRelationError,
              _e,
            ),
          )
      )
      onDragLeave=(
        _e =>
          send(
            DragEventUtils.handleDragLeave(
              folderId,
              handleFlag,
              handleRelationError,
              _e,
            ),
          )
      )
      onDragOver=DragEventUtils.handleDragOver
      onDrop=(
        _e =>
          send(
            DragEventUtils.handleDrop(
              folderId,
              handleFlag,
              handleRelationError,
              _e,
            ),
          )
      )
    />
    <img src=imgSrc />
    <span className="item-text"> (DomHelper.textEl(name)) </span>
  </article>;
};

let make = (~store, ~dispatchFunc, ~attributeTuple, ~funcTuple, _children) => {
  ...component,
  reducer: reducer(funcTuple),
  initialState: () => {
    let (dragImg, imgSrc, folderId, name, isSelected, flag) = attributeTuple;
    isSelected ?
      {style: ReactDOMRe.Style.make(~background="red", ())} :
      {style: ReactDOMRe.Style.make(~border="1px solid red", ())};
  },
  didMount: _self => {
    let (_dragImg, _imgSrc, folderId, _name, _isSelected, _flag) = attributeTuple;

    let clickStream =
      Most.fromEvent(
        "mousedown",
        DomHelper.getElementById("folder-" ++ string_of_int(folderId))
        |> Obj.magic,
        true,
      );

    clickStream
    |> ClickStreamUtils.bindClickStream(~isSingleClick=false)
    |> Most.forEach(_event => {
         WonderLog.Log.print("double click11") |> ignore;
         Method.onDoubleClick(dispatchFunc, folderId);
       })
    |> ignore;

    clickStream
    |> ClickStreamUtils.bindClickStream(~isSingleClick=true)
    |> Most.forEach(event => {
         WonderLog.Log.print("single click") |> ignore;
         Method.onClick(folderId, dispatchFunc, event);
       })
    |> ignore;
  },
  render: self =>
    render(store, dispatchFunc, attributeTuple, funcTuple, self),
};